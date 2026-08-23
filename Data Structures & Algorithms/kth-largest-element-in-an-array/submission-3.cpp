class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left{};
        int right = nums.size() - 1;

        while(left <= right){
            int index = partition(left, right, nums);
            if(index == target){
                return nums[index];
            }
            else if(index < target){
                left = index +1;
            }
            else{
                right = index -1;
            }
        }
        return -1;
    }

  private:
    int partition(int left, int right, std::vector<int> &nums) {
      // Wir müssen das wie Binary machen aber nur mit einer..
      int pivot = nums[right];
      int index = left;

      for (int i = left; i < right; ++i) {
        if (nums[i] < pivot) {
          std::swap(nums[index], nums[i]);
          ++index;
        }
      }
      std::swap(nums[right], nums[index]);
      return index;
    }
};