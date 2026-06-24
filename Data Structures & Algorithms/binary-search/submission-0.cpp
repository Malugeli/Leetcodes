struct Solution{
    int search(std::vector<int>& nums, int target){
        int left{};
        int right = nums.size() - 1;
        while(left <= right){
            int mid = std::midpoint(left, right);
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};