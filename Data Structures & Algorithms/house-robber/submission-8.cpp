class Solution {
public:
  int rob(std::vector<int> &nums) {
    if (nums.size() < 2) {
      return nums[0];
    }

    int best0 = nums[0];
    int best1 = std::max(nums[1], best0);

    for (int i = 2; i < nums.size(); ++i) {
      int current = std::max(best0 + nums[i], best1);
      best0 = best1;
      best1 = current;
    }
    return best1;
  }
};
