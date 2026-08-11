class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> seen_nums{nums.begin(), nums.end()};
        int longest{};

        for(int i : seen_nums){
            if(seen_nums.contains(i - 1)){
                continue;
            }

            int current_length = 1;
            while(seen_nums.contains(i + current_length)){
                ++current_length;
            }

            longest = std::max(current_length, longest);
        }
        return longest;
    }
};