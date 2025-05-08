class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int n = mt.size(), m = mt[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq;
        
        time[0][0] = 0;
        pq.push({0, 0, 0, 1});
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [t, x, y, val] = pq.top(); pq.pop();
            
            if (t > time[x][y]) continue;
            
            if (x == n-1 && y == m-1) return t;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                int new_val = (val == 1) ? 2 : 1;
                int nt = max(t + val, mt[nx][ny] + val);

                if (nt < time[nx][ny]) {
                    time[nx][ny] = nt;
                    pq.push({nt, nx, ny, new_val});
                }
            }
        }
        
        return -1; 
    }
};
