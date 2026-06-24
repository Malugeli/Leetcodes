//Binary Search
#include <ranges>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target){
        for(auto [key, value] : std::views::enumerate(numbers)){
            int searched_int = target - value;
            int first = key + 1;
            int last = numbers.size() - 1;
            while(first <= last){
                int mid = std::midpoint(first, last);
                if(numbers[mid] == searched_int){
                    return {static_cast<int>( key ) + 1, mid + 1};
                }
                else if(numbers[mid] < searched_int){
                    first = mid + 1;
                }
                else{
                    last = mid - 1;
                }
            }
        }
        return {};  
    }
};
