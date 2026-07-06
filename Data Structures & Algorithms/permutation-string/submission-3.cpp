//nicht meine Lösung!   

//bessere Variablennamen, weniger Memory und eleganter mit dem fixed Window wo window[s2[i - s1.size()]- 'a'] den letzten Buchstaben aus dem Window entfernt!
//Wunderschön

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) return false;

        std::array<int, 26> need{};
        std::array<int, 26> window{};
        for (char c : s1) need[c - 'a']++;

        for (size_t i = 0; i < s2.size(); ++i) {
            window[s2[i] - 'a']++;
            if (i >= s1.size()) {
                window[s2[i - s1.size()] - 'a']--;
            }
            if (i >= s1.size() - 1 && window == need) {
                return true;
            }
        }
        return false;
    }
};
