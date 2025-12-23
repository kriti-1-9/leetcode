class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: push all rotten oranges & count fresh
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        // No fresh oranges → time = 0
        if (fresh == 0) return 0;

        int minutes = -1;
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Step 2: BFS level-by-level
        while (!q.empty()) {
            int size = q.size();
            minutes++;

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto &d : dirs) {
                    int nx = x + d[0], ny = y + d[1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // rot it
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // If fresh left → impossible
        if (fresh > 0) return -1;
        return minutes;
    }
};