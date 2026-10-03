class Solution {
public:
  int rob(std::vector<int> &nums) {
    if (nums.size() < 2) {
      return nums[0];
    }
    std::vector<int> best(nums.size(), -1);

    best[0] = nums[0];
    best[1] = std::max(nums[1], best[0]);

    for (int i = 2; i < nums.size(); ++i) {
      best[i] = std::max(nums[i] + best[i - 2], best[i - 1]);
    }
    return best[nums.size() - 1];
  }};
