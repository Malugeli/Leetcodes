// Ohne DRY und die unnötigen Branches.. Leetcode Hard geschafft LETS GOOOO!

class Solution{
    public:
        int trap(std::vector<int>& height){
            int left = 0;
            int right = static_cast<int>(height.size()) -1;
            int left_max{};
            int right_max{};
            int water{};

            while(left < right){
                left_max = std::max(height[left], left_max);
                right_max = std::max(height[right], right_max);
                if(left_max <= right_max){
                  water += left_max - height[left];
                  left++;
                }
                else{
                  water += right_max - height[right];
                  right--;
                }
            }
            return water;
        }
};