class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        const size_t row = grid.size();
        const size_t col = grid[0].size();
        int island{};
        const std::array<std::array<int, 2>, 4> direction{{
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        }};

        for(size_t r = 0; r < row; ++r){
            for(size_t c = 0; c < col; ++c){
                if(grid[r][c] == '0'){
                    continue;
                }

                ++island;
                grid[static_cast<size_t>(r)][static_cast<size_t>(c)] = '0';
                std::stack<std::pair<int, int>> island_part{};
                island_part.push({r, c});

                while(!island_part.empty()){
                    auto cords = island_part.top();
                    island_part.pop();
                    for(auto dir : direction){
                        int nr = cords.first + dir[0];
                        int nc = cords.second + dir[1];
                        bool inside = nr >= 0 && nr < static_cast<int>(row) &&
                                      nc >= 0 && nc < static_cast<int>(col);
                        if(inside && grid[static_cast<size_t>( nr )][static_cast<size_t>( nc )] == '1'){
                            island_part.push({nr, nc});
                            grid[static_cast<size_t>(nr)]
                                [static_cast<size_t>(nc)] = '0';
                        }
                    }
                }
            }
        }

        return island;
    }
};