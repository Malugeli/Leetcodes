class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtracking(target, 0, result, current, nums);

        return result;

    }
private:
    void backtracking(int target, int start, std::vector<std::vector<int>>& result, std::vector<int>& current, std::vector<int>& nums){
        //Basisfall
        if(target < 0){
            return;
        }
        else if(target == 0){
            result.push_back(current);
            return;
        }

        //wir machen das mit Loop
        for(int i = start; i < static_cast<int>( nums.size() ); ++i){
            current.push_back( nums[i] );
            backtracking(target - nums[i], i, result, current, nums);
            current.pop_back();
        }
        
    }
};