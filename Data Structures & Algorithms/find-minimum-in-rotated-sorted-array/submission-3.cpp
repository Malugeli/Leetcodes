class Solution{
public:
    int findMin(std::vector<int>& nums){
        int left{};
        int right = static_cast<int>(nums.size() -1);
        while(left < right){
           int mid = std::midpoint(left, right);
           if(nums[mid] > nums[right]){
            left = mid +1;
           }
           else{
            right = mid;
           }
        }
        return nums[left];
    }
};