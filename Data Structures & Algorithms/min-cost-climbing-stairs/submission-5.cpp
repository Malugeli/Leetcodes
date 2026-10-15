class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {
    size_t prev1{};
    size_t prev2{};
    for (int i = 2; i <= cost.size(); ++i) {
      int best = std::min(cost[i - 1] + prev1, cost[i - 2] + prev2);
      prev2 = prev1;
      prev1 = best;
    }
    return prev1;
  }
};
