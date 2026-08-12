class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) return false;

        std::array<int, 26> need{};
        std::array<int, 26> window{};
        for (char c : s1) need[c - 'a']++;

        int matches = 0;
        for(size_t i = 0; i < need.size(); ++i){
            if(need[i] == 0){
                matches++;
            }
        }
        for (size_t i = 0; i < s2.size(); ++i) { 
            int c = s2[i] - 'a';
            window[c]++;
            if (window[c] == need[c]) matches++;
            else if (window[c] == need[c] + 1) matches--;

            //Wenn das Window zu groß wird
            if (i >= s1.size()) {
                int left = s2[i - s1.size()] - 'a';
                window[left]--;
                if (window[left] == need[left]) matches++;
                else if (window[left] == need[left] - 1) matches--;
            }

            if (i >= s1.size() - 1 && matches == 26) {
                return true;
            }
        }
        return false;
    }
};