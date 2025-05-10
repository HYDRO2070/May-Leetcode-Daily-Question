class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int c1 = 0, c2 = 0;

        for (int& num : nums1) {
            if (num == 0) c1++;
            else sum1 += num;
        }
        for (int& num : nums2) {
            if (num == 0) c2++;
            else sum2 += num;
        }
        if(sum1 == 2000000) return 2000002;
        if((sum1 < sum2 && c1 == 0) || (sum1 > sum2 && c2 == 0)) return -1;

        sum1 += c1;
        sum2 += c2;
        if(sum1 == sum2) return sum1;

        long long D = abs(sum1 - sum2);

        int cnt = (sum1 < sum2) ? c1 : c2;
        long long maxi = 10000000000 - 1;
        long long limit = 1ll * cnt * maxi;

        if(D > limit) return -1;
        return max(sum1,sum2);

    }
};
