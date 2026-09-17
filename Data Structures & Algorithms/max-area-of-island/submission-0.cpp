class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        const size_t row = grid.size();
        const size_t col = grid[0].size();
        int max_area{};
        const std::array<std::array<int, 2>, 4> direction{
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        for(size_t r = 0; r < row; ++r){
            for(size_t c = 0; c < col; ++c){
                if(grid[r][c] == 0){
                    continue;
                }

                int area = 1;
                std::stack<std::pair<int, int>> cords;
                cords.push({r, c});
                grid[r][c] = 0;

                while(!cords.empty()){
                    auto cord = cords.top();
                    cords.pop();
                    for (auto dir : direction) {
                      int nr = cord.first + dir[0];
                      int nc = cord.second + dir[1];
                      bool inside = nr >= 0 && nr < static_cast<int>(row) &&
                                    nc >= 0 && nc < static_cast<int>(col);
                      if (inside && grid[static_cast<size_t>(nr)]
                                        [static_cast<size_t>(nc)] == 1){
                                            grid[static_cast<size_t>( nr )][static_cast<size_t>(nc)] = 0;
                                            cords.push({nr, nc});
                                            ++area;
                                        }
                    }
                }
                max_area = std::max(max_area, area);
            }
        }
        return max_area;
    }
};
