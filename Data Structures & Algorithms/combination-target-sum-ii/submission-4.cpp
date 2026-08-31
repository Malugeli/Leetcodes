class Solution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    std::ranges::sort(candidates);
    backtracking(result, current, candidates, target, 0);
    return result;
  }

private:
void backtracking(
    std::vector<std::vector<int>>& result,
    std::vector<int>& current,
    std::vector<int>& candidates,
    int remaining,
    int start
){
    //Basisfall zuerst:
    if(remaining == 0){
        result.push_back(current);
        return;
    }

    //brauche ich innerhalb der Loop nochmal? Weil innerhalb der loop rufen wir die Funktion sowieso auf?
    if(start >= candidates.size() || candidates[start] > remaining){
        return;
    }

    for(int i = start; i < static_cast<int>( candidates.size() ); ++i){
        if(i > start && candidates[i] == candidates[i - 1]){
            continue;
        }

        current.push_back(candidates[i]);

        backtracking(result, current, candidates, remaining - candidates[i], i + 1);

        current.pop_back();
    }
}
};