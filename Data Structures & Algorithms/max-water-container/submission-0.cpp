struct Solution{
    int maxArea(std::vector<int>& heights){
        int left = 0;
        int right = heights.size() - 1;
        int water = 0;
        while(left < right){
           int current = std::min(heights[left], heights[right]) * (right - left);
           water = std::max(current, water);
           if(heights[left] < heights[right]){
            left++;
           }
           else right--;
        }
        return water;
    }
};