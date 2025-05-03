class Solution {
public:
    bool helper_function(int mid, vector<int>& tasks, vector<int>& workers,
                         int pills, int strength) {
        multiset<int> availableWorkers(workers.begin(), workers.begin() + mid);
        int pillsUsed = 0;

        for (int i = mid - 1; i >= 0; i--) {
            int task = tasks[i];

            auto it = prev(availableWorkers.end());

            if (*it >= task) {
                availableWorkers.erase(it);
            } else if (pillsUsed < pills) {
                auto it2 = availableWorkers.lower_bound(task - strength);
                if (it2 == availableWorkers.end())
                    return false;

                availableWorkers.erase(it2);
                pillsUsed++;
            } else {
                return false;
            }
        }

        return true;
    
} int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                    int strength) {
    int n = tasks.size();
    int m = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end(), greater<int>());

    int low = 0, high = min(n, m);
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (helper_function(mid, tasks, workers, pills, strength)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
}
;
