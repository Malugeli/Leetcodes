class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        const int rows = grid.size();
        const int cols = grid[0].size();
        const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int islands = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] != '1') {
                    continue;
                }

                ++islands;

                queue<pair<int, int>> todo;
                todo.push({r, c});
                grid[r][c] = '0';            // sofort markieren!

                while (!todo.empty()) {
                    auto [cr, cc] = todo.front();
                    todo.pop();

                    for (const auto& dir : dirs) {
                        const int nr = cr + dir[0];
                        const int nc = cc + dir[1];
                        const bool inside =
                            nr >= 0 && nr < rows &&
                            nc >= 0 && nc < cols;

                        if (inside && grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';   // beim Einfügen markieren
                            todo.push({nr, nc});
                        }
                    }
                }
            }
        }

        return islands;
    }
};