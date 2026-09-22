
class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        size_t left{};
        size_t right = heights.size()- 1;
        int water{};

        while(left < right){
            int length = static_cast<int>( right - left );
            int current_water = length * std::min(heights[left], heights[right]);
            water = std::max(water, current_water);

            if(heights[right] < heights[left]){
                --right;
            }
            else{
                ++left;
            }
        }

        return water;
    }
};