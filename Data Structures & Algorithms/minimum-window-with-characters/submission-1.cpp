class Solution{
    public:
    std::string minWindow(std::string s, std::string t){
        std::array<int, 123> need{};
        if(t.size() > s.size()){
            return "";
        }

        for(auto c : t){
            need[c]++;
        }
        auto len = std::string::npos; // Sentinelwert
        int left{}; 
        int best_start{};
        int missing = static_cast<int>(t.size());


        for(size_t right = 0; right < s.size(); ++right){
            if(need[s[right]] > 0){
                missing--;
            }
            need[s[right]]--;

            while (!missing) {
              size_t bestlen = right - left + 1;

              if (bestlen < len) {
                best_start = left;
                len = bestlen;
              }
              need[s[left]]++;
              if(need[s[left]] > 0){
                missing++;
              }
              left++;
            }
        }
        return len == std::string::npos ? "" : s.substr(best_start, len);
    }
};