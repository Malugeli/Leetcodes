class Solution{
   public:
   std::vector<int> productExceptSelf(std::vector<int>& nums){
        //wir machen erstmal das mit Division und danach das Follow-up.
        std::vector<int> left(nums.size());
        std::vector<int> right(nums.size());
        std::vector<int> output(nums.size());
        std::ranges::fill(left, 1);
        std::ranges::fill(right, 1);

        for(size_t i = 1; i < nums.size(); ++i){
            left[i] = nums[i - 1] * left[i - 1];
        }

        for(int i = static_cast<int>(nums.size()) - 2; i >= 0; --i){
            right[i] = nums[i + 1] * right[i + 1];
        }

        for(size_t i = 0; i < nums.size(); ++i){
            output[i] = left[i] * right[i];
        }
        return output;
   }
};