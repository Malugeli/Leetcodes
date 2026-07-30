class Solution{
    public:
    std::string minWindow(std::string& s, std::string t){
        if(t.size() > s.size()){
            return "";
        }
        
        std::array<int, 123> need{};
        for(auto c : t){
            ++need[c];
        }
        
        auto best_len = std::string::npos; //"unendlich"
        size_t best_start{};
        auto missing = t.size();
        size_t left{}; 

        for(size_t right = 0; right < s.size(); ++right){
            char c = s[right];
            if(need[c] > 0){
                --missing;
            }
            --need[c];
            while(missing == 0){
               c = s[left];
               size_t len = right - left +1;
               if(len < best_len){
                best_len = len;
                best_start = left;
               }
               ++need[c];
               if(need[c] > 0){
                   ++missing;
                }
                left++;
            }
        }
        
        return best_len == std::string::npos ? "" : s.substr(best_start, best_len);

    }
};