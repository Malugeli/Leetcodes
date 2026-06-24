class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int result = 0;
        int water = 0;

        while(left < right){
            water = std::min(heights[left], heights[right]) * (right - left);
            result = std::max(water, result);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};
