class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(
        std::vector<int>& candidates,
        int target
    ) {
        std::ranges::sort(candidates);

        std::vector<std::vector<int>> result;
        std::vector<int> current;

        backtrack(candidates, target, 0, current, result);

        return result;
    }

private:
    void backtrack(
        const std::vector<int>& candidates,
        int remaining,
        int start,
        std::vector<int>& current,
        std::vector<std::vector<int>>& result
    ) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > remaining) {
                break;
            }

            current.push_back(candidates[i]);

            backtrack(
                candidates,
                remaining - candidates[i],
                i + 1,
                current,
                result
            );

            current.pop_back();
        }
    }
};