struct Solution{
std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    std::ranges::sort(nums);
    std::vector<std::vector<int>> result;
    for(int i = 0; i < nums.size() - 2; ++i){
        if(nums[i] > 0 || nums[i] + nums[i + 1] > 0) break;
    
        if(i > 0 && nums[i] == nums[i - 1]){ // short-circuit evalution
            continue;
        }
            
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            if(sum == 0){
                result.push_back({nums[left], nums[right], nums[i]});
                while(left < right && nums[left] == nums[left + 1]){
                    left++;
                }
            
                while(left < right && nums[right] == nums[right - 1]){
                    right--;
                }
                left++;
                right--;
            }
            else if(sum > 0){
                right--;
            }
            else{
                left++;
            }
        }
    }
    return result;
}
}; 