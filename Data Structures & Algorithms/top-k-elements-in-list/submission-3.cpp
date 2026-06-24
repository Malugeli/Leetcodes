#include <ranges>

struct Solution{
    std::vector<int> topKFrequent(std::vector<int>& nums, int k){
        std::array<uint16_t, 2001> numbers{};
        for(auto num : nums){
            numbers[num + 1000]++;
        }

        std::vector<std::vector<int>> amount(nums.size() + 1);
        
        for(auto [number, count] : numbers | std::views::enumerate){
            if(count == 0){
                continue;
            }
            amount[count].push_back(number -1000);
        }

        std::vector<int> result;
        result.reserve(k);

        for(auto& bucket : amount | std::views::reverse){
            for(auto num : bucket){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        
        return result;
    }
};