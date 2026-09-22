class Solution{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k){
        std::priority_queue<std::pair<int,int>, std::deque<std::pair<int,int>>, std::greater<std::pair<int,int>>> frequenz;
        std::array<int, 2001> amount{};

        for(auto num : nums){
            size_t index = static_cast<size_t>( num + 1000 );
            ++amount[index];
        }

        for(size_t i = 0; i < amount.size(); ++i){
            if(amount[i] == 0){
                continue;
            }
            if(frequenz.size() < static_cast<size_t>( k )){
                frequenz.push({amount[i], i});
            }
            else{
                if(frequenz.top().first < amount[i]){
                    frequenz.pop();
                    frequenz.push({amount[i], i});
                }
                else continue;
            }
        }
    
    std::vector<int> result;
    for(int i = 0; i < k; ++i){
        result.push_back(frequenz.top().second -1000);
        frequenz.pop();
    }
    return result; 
   }
};