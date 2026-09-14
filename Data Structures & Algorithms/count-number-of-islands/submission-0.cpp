class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        const int rows = grid.size();
        const int cols = grid[0].size();
        const int directions[4][2] = {
            {-1, 0}, // oben
            {1, 0},  // unten
            {0, -1}, // links
            {0, 1}   // rechts
        };

        int islands = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] != '1') {
                    continue;
                }

                ++islands;

                stack<pair<int, int>> cells;
                cells.push({row, col});
                grid[row][col] = '0';

                while (!cells.empty()) {
                    auto [currentRow, currentCol] = cells.top();
                    cells.pop();

                    for (const auto& direction : directions) {
                        const int nextRow = currentRow + direction[0];
                        const int nextCol = currentCol + direction[1];

                        const bool insideGrid =
                            nextRow >= 0 && nextRow < rows &&
                            nextCol >= 0 && nextCol < cols;

                        if (insideGrid && grid[nextRow][nextCol] == '1') {
                            grid[nextRow][nextCol] = '0';
                            cells.push({nextRow, nextCol});
                        }
                    }
                }
            }
        }

        return islands;
    }
};
