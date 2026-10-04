struct Solution{
    int lengthOfLongestSubstring(std::string s){
       std::array<int, 128> seen;
       std::ranges::fill(seen, -1);

       int left{};
       int result{};

       for(int right = 0; right < s.size(); ++right){
         if (seen[s[right]] >= left){
            left = seen[s[right]] + 1;
         }
         seen[s[right]] = right;
         result = std::max(result, right - left + 1);
       }
       return result;
    } 
};
