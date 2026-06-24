#include <ranges>

struct Solution{
std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    std::ranges::sort(nums);
    std::vector<std::vector<int>> result;

    for(auto [index, num] : nums | std::views::enumerate){
        int i = index;
        int j = nums.size() - 1;
        int k = index + 1;
        while(j > k && i < k){
            int x = nums[ i ] + nums[ j ] + nums[ k ];
            if(x > 0){
                j--;
            }
            else if(x < 0){
                k++;
            }
            else{
                std::vector<int> sum{{ nums[i], nums[j], nums[k] }};
                if(!std::ranges::contains(result, sum))
                {
                  result.push_back(sum);
                }
                k++;
            }
        } 
    }
    return result;
}
}; 