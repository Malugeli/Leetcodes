class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        backtracking(current, result, nums);
        return result;
    }

private:
  void
  backtracking(std::vector<int> &current, std::vector<std::vector<int>> &result,
               std::vector<int> &nums,
               int i = 0) { // Meine erste Frage ist schon wer von denen als ref
                            // oder cp? Vermutung: current als copy aber idk
    // Basisfall:
    if (i == static_cast<int>(nums.size())) {
      result.push_back(current);
      return;
    }

    current.push_back(nums[i]);

    backtracking(current, result, nums, i + 1);
    current.pop_back();

    backtracking(current, result, nums, i + 1);
  }
};