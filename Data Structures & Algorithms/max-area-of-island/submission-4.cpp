class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    int maxArea{};
    std::array<std::pair<int, int>, 4> direction{
        {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

    for (int y = 0; y < static_cast<int>(grid.size()); ++y) {
      for (int x = 0; x < static_cast<int>(grid[0].size()); ++x) {
        if (grid[y][x] == 0) {
          continue;
        }
        std::stack<std::pair<int, int>> check;
        grid[y][x] = 0;
        check.push({y, x});
        int area = 1;

        while (!check.empty()) {
          auto cords = check.top();
          check.pop();
          for (auto dir : direction) {
            int vertical = cords.first + dir.first;
            int horizontal = cords.second + dir.second;

            bool inside = vertical < static_cast<int>(grid.size()) &&
                          vertical >= 0 &&
                          horizontal < static_cast<int>(grid[0].size()) &&
                          horizontal >= 0;

            if (inside && grid[vertical][horizontal] == 1) {
              grid[vertical][horizontal] = 0;
              check.push({vertical, horizontal});
              ++area;
            }
          }
        }
        maxArea = std::max(area, maxArea);
      }
    }
    return maxArea;
  }
};
