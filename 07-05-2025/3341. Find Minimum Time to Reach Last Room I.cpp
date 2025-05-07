class Solution {
    // private:
    // int n,m;
    // vector<vector<bool>> visit;
    // void solve(vector<vector<int>>& mt,int i,int j,int val,int &res){
    //     if(i < 0 || j < 0 || i >= n || j >= m || visit[i][j]) return;
    //     if(i == n-1 && j == m-1){
    //         res = min(res,max(val+1,mt[i][j]+1));
    //         return;
    //     }
    //     visit[i][j] = true;
    //     int curr = max(val+1,mt[i][j]+1);
    //     if(i == 0 && j == 0) curr = 0;
    //     solve(mt,i,j-1,curr,res);
    //     solve(mt,i-1,j,curr,res);
    //     solve(mt,i+1,j,curr,res);
    //     solve(mt,i,j+1,curr,res);
    //     visit[i][j] = false;
    // }
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        // n = mt.size();
        // m = mt[0].size();
        // visit.resize(n,vector<bool>(m,false));
        // mt[0][0] = 0;
        // int res = INT_MAX;
        // solve(mt,0,0,0,res);
        // return  res;


        int n = mt.size(), m = mt[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        
        time[0][0] = 0;
        pq.push({0, 0, 0});
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto [t, x, y] = pq.top(); pq.pop();
            
            if (t > time[x][y]) continue;
            
            if (x == n-1 && y == m-1) return t;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                int nt = max(t + 1, mt[nx][ny] + 1);
                
                if (nt < time[nx][ny]) {
                    time[nx][ny] = nt;
                    pq.push({nt, nx, ny});
                }
            }
        }
        
        return -1; 
    }
};
