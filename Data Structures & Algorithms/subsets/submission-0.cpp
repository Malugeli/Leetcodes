//erstes Backtracking.. basically unsere Chess Engine Search gebruteforced

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);

        return result;
    }

private:
    void backtrack(
        int i,
        const vector<int>& nums,
        vector<int>& current,
        vector<vector<int>>& result
    ) {
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }

        // Entscheidung 1:
        // nums[i] nehmen
        current.push_back(nums[i]);

        backtrack(i + 1, nums, current, result);

        // Entscheidung rückgängig machen
        current.pop_back();

        // Entscheidung 2:
        // nums[i] nicht nehmen
        backtrack(i + 1, nums, current, result);
    }
};
