class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> bfsq;
        int fresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) { 
                    bfsq.push(make_pair(i,j));
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int minutes = 0;
        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!bfsq.empty()) {
            int size = bfsq.size();
            bool rotten = false;
            for(int i = 0; i < size; i++) {
                auto t = bfsq.front();
                bfsq.pop();
                for(auto x : dir) {
                    int x1 = x.first + t.first;
                    int y1 = x.second + t.second;
                    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && grid[x1][y1] == 1) {
                        grid[x1][y1] = 2;
                        fresh--;
                        bfsq.push({x1, y1});
                        rotten = true;
                    }
                }
            }   
            if(rotten) minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};
