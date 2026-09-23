class Solution {
public:
    int search(std::vector<int>& nums, int target) {
       int left{};
       int right = nums.size() -1;

       while(left <= right){
        int mid = left + (right - left) /2;
        if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            return static_cast<int>(mid);
        }
       }
       return -1;
    }
};
