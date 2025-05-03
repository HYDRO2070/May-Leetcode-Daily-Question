class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int digits = int(floor(log10(x)) + 1);
            if (digits % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};
