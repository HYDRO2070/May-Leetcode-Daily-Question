class Solution {
private:
    int ispossible(vector<int>& t, vector<int>& b, int num) {
        int n = t.size();
        int ra = 0, rb = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] != num && b[i] != num)
                return -1;
            else if (t[i] != num)
                ra++;
            else if (b[i] != num)
                rb++;
        }
        return min(ra, rb);
    }

public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int cnt = ispossible(t, b, t[0]);
        if (cnt != -1)
            return cnt;
        if (t[0] != b[0]) {
            cnt = ispossible(t, b, b[0]);
            if (cnt != -1)
                return cnt;
        }
        return -1;
    }
};
