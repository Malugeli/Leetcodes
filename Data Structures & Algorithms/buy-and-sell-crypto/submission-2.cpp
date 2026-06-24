struct Solution{
    int maxProfit(std::vector<int>& prices){

      int small{};
      int big{};
      int profit{};
      int i = 0;
      int j = i + 1;
      while (j < prices.size()) {
        if (prices[j] > prices[i] && prices[j] > big) {
          big = prices[j];
          if(prices[j] - prices[i] > profit)
          {profit = prices[j] - prices[i];}
        }
        if (prices[j] < prices[i]) {
          small = prices[j];
          big = 0;
          i = j;
        }
        j++;
      }
        return profit;
    }
};