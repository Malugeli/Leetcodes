class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
             if (s1.size() < 2) {
        return s2.contains(s1);
      }


       std::array<int, 26> seen{};
       for(char c : s1){
        seen[c - 'a']++;
       }

       for(size_t left = 0; left < s2.size(); ++left){
        if(seen[s2[left] - 'a']){
            auto check = seen;
            check[s2[left] - 'a']--;
            auto right = left + 1;
            size_t count = 1;
            while(right < s2.size() && check[s2[right] - 'a']){
                count++;
                if(count == s1.size()){
                    return true;
                }
                check[s2[right] - 'a']--;
                right++;
            }
        }
       }
       return false;
    }
};