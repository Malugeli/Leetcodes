class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;        
        std::vector<int> current;
        std::vector<bool> seen(nums.size(), false);
        backtracking(result, current, nums, seen);
        return result;

    }

private:
    void backtracking(std::vector<std::vector<int>>& result, std::vector<int>& current, std::vector<int>& nums, std::vector<bool>& seen){
        //Basisfall was genau?
        if(current.size() == nums.size()){
            result.push_back( current );
            return;
        }

        for(size_t i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(seen[i]){
                continue;
            }
            seen[i] = true;
            current.push_back(num);

            backtracking(result, current, nums, seen);

            seen[i] = false;
            current.pop_back();
        }
    }
};