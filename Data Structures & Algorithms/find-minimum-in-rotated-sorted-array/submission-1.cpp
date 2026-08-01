class Solution{
public:
    int findMin(std::vector<int>& nums){
        int left = 0;
        int right = static_cast<int>(nums.size() -1);
        int min = nums[left];
        while(left <= right){
            min = std::min(std::min(nums[left], nums[right]), min);
            if(nums[left] < nums[right]){
                break;
            }
            ++left;
            --right;
        }
        return min;
    }
};