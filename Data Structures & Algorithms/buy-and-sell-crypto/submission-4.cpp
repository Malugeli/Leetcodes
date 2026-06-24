class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit{};
        int minPrice = prices[0];

        for(auto price : prices){
          profit = std::max(profit, price - minPrice);
          minPrice = std::min(minPrice, price);
        }
        return profit;
    }
};
