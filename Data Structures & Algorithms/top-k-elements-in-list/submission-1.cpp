struct Solution{
    std::vector<int> topKFrequent(std::vector<int>& nums, int k){
        std::unordered_map<int, int> numbers;
        for(auto num : nums){
                numbers[num]++;
        }

        std::vector<std::vector<int>> amount(nums.size() + 1);

        for(auto& num : numbers){
            amount[num.second].push_back(num.first);
        }

        std::vector<int> result;
        result.reserve(k);

        for(int i = amount.size() -1; i > 0; --i){
            if(amount[i].empty()){
                continue;
            }
            for(auto num : amount[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }

        return result;
        }
    };
