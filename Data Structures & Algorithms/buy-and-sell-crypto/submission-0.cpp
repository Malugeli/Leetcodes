struct Solution{
    int maxProfit(std::vector<int>& prices){
        int x = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            for(int j = i + 1; j < prices.size(); ++j){
                if(prices[j] - prices[i] > x){
                    x = prices[j] - prices[i];
                }

            }
        }
        return x;
    }

};  