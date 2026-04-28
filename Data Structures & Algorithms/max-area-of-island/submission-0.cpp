class Solution {
    int bfs(int n, int m, pair<int,int> src, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int,int>> bfsq;
        bfsq.push(src);
        visited[src.first][src.second] = true;
        int area = 1;
        while(!bfsq.empty()) {
            auto t = bfsq.front();
            bfsq.pop();
            for(auto x : dir) {
                int x1 = x.first + t.first;
                int y1 = x.second + t.second;
                if(x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && 
                    !visited[x1][y1] && grid[x1][y1] == 1) {
                        bfsq.push({x1, y1});
                        visited[x1][y1] = true;
                        area++;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    maxArea = max(maxArea, bfs(n, m, make_pair(i,j), grid, visited));
                }
            }
        }
        return maxArea;
    }
};
