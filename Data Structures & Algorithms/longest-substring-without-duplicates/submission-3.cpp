#include <ranges>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::array<int, 128> seen;
        std::ranges::fill(seen, -1);

        int result{};
        int left{};

        for(int right = 0; right < s.size(); ++right){
            int ch = s[right];
            if(seen[ch] >= left){
                left = seen[ch] + 1;
            }
            seen[ch] = right;
            result = std::max(result, right - left + 1);
        }
        return result;
    }
};
