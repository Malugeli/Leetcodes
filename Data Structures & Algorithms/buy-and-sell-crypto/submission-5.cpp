class Solution{
    public:
    int maxProfit(std::vector<int>& prices){
    
        int min = prices[0];
        int profit{};
        for(size_t right = 0; right < prices.size(); ++right){
            min = std::min(prices[right], min);
            profit = std::max(profit, static_cast<int>(prices[right] - min));
        }
        return profit;
    }
};