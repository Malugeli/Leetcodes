class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::ranges::sort(nums);

    for (size_t i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      if (nums[i] > 0)
        break;
      
      size_t left = i + 1;
      size_t right = nums.size() - 1;
    //   if (nums[i] + nums[left] > 0)
    //     break;

      while (left < right) {
        int target = nums[i] + nums[left] + nums[right];
        if (target == 0) {
          result.push_back({nums[i], nums[left], nums[right]});
          int left_value = nums[left];
          int right_value = nums[right];

          while (left < right && nums[left] == left_value) {
            ++left;
          }
          while (left < right && nums[right] == right_value) {
            --right;
          }
        } else if (target > 0) {
          --right;
        } else {
          ++left;
        }
      }
    }

    return result;
  }
};