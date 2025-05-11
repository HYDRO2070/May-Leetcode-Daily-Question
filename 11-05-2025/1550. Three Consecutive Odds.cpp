class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        char cnt = '0';
        for(auto& num : arr){
            if(num&1){
                cnt++;
                if(cnt == '3') return true;
            }
            else cnt = '0';
        }
        return false;
    }
};
