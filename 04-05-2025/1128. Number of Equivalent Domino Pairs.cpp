class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        const int n = d.size();
        int res = 0;

        for(int i = 0;i < n-1;i++){
            const pair<int,int> one = {d[i][0],d[i][1]};
            for(int j = i+1;j < n;j++){
                const pair<int,int> two = {d[j][0],d[j][1]};
                if((one.first == two.first && one.second == two.second) || (one.second == two.first && one.first == two.second)){
                    res++;
                }
            }
        }
        return res;
    }
};
