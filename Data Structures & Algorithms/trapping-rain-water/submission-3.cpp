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
                while(left < right && left_max <= right_max){
                    if(height[left] < left_max){
                        water += left_max - height[left];
                    }
                    left++;
                    left_max = std::max(height[left], left_max);
                }
                while(left < right && right_max < left_max){
                    if(height[right] < right_max){
                        water += right_max - height[right];
                    }
                    right--;
                    right_max = std::max(height[right], right_max);
                }
            }
            return water;
        }
};