class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &nums,
                                                 int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtracking(result, nums, current, target);
        return result;

    }

private:
    void backtracking(std::vector<std::vector<int>> &result,
                      std::vector<int> &nums, std::vector<int> &current,
                      int remaining, int index = 0) {
        if(remaining < 0){
            return;
        }
        else if(remaining == 0){
            result.push_back(current);
        }
        for (int i = index; i < nums.size(); ++i) {
            current.push_back(nums[static_cast<size_t> (i)]);
            backtracking(result, nums, current, remaining - nums[i], i);
            current.pop_back();
        }

    }
};

