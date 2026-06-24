struct Solution{
    std::vector<int> topKFrequent(std::vector<int>& nums, int k){
        std::unordered_map<int, int> numbers;
        for(auto num : nums){
            if(numbers.contains(num)){
                numbers.at(num)++;
            }
            else{
                numbers.emplace(num, 1);
            }
        }
        std::vector<int> result;
        result.reserve(k);

        for(int i = 0; i < k; ++i){
            auto it = std::ranges::max_element(numbers, std::less{}, [](const auto& pair){return pair.second;});
            result.push_back(it->first);
            numbers.erase(it);
        }

        return result;

    }
};
