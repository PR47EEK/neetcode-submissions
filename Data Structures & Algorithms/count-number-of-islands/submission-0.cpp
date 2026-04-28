class Solution {
    void bfs(pair<int,int> src,vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};
        queue<pair<int,int>> bfsq;
        bfsq.push(src);
        visited[src.first][src.second] = true;
        while(!bfsq.empty()) {
            auto t = bfsq.front();
            bfsq.pop();
            for(auto x : dir) {
                int x1 = t.first + x.first;
                int y1 = t.second + x.second;
                if( x1 >= 0 && x1 < n 
                    && y1 >= 0 && y1 < m && !visited[x1][y1] && grid[x1][y1] == '1') {
                    bfsq.push(make_pair(x1,y1));
                    visited[x1][y1] = true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    bfs(make_pair(i, j), grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
