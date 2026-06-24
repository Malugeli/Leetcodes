struct Solution{
    int lengthOfLongestSubstring(std::string s){
        int result{};
        int amount{};
        std::array<bool, 95> seen{};

        for(int i = 0; i < s.size(); ++i){
            amount++;
            seen[s[i] - 32] = true;
            int next = i + 1;
            while(next < s.size() && !seen[s[next] - 32]){
                seen[s[next] - 32] = true;
                amount++;
                next++; 
            }
            result = std::max(amount, result);
            amount = 0;
            std::ranges::fill(seen, false);
        }
        return result;
    } 
};