class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
      int profit{};
      size_t left{};

      for (size_t right = 0; right < prices.size(); ++right) {
        if (prices[right] < prices[left]) {
          left = right;
        } else {
          int current = prices[right] - prices[left];
          profit = std::max(profit, current);
        }
      }
      return profit;
    }
};