class Solution{
    public:
    int longestConsecutive(std::vector<int>& nums){
        std::unordered_set<int> check(nums.begin(), nums.end());
        int result{};
        for(auto i : nums){
            if(!check.contains(i - 1)){
                int amount = 1;
                int consecutive = i; 
                while(check.contains( consecutive + 1 )){
                    ++amount;
                    ++consecutive;
                }
                result = std::max(result, amount);
            }
            continue;
        }
        return result;
    }
};