class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) return false;

        std::array<int, 26> need{};
        std::array<int, 26> window{};
        for (char c : s1) need[c - 'a']++;
        size_t required_char{};
        for(int i : need){
            if(i > 0){
                ++required_char;
            }
        }

        size_t counter{};

        for (size_t i = 0; i < s2.size(); ++i) { 
            int c = s2[i] - 'a';
            window[c]++;
            if (window[c] == need[c]) counter++; 
            else if (window[c] == need[c] + 1) counter--; 

            //Wenn das Window zu groß wird
            if (i >= s1.size()) {
                int left = s2[i - s1.size()] - 'a';
                window[left]--;
                if (window[left] == need[left]) counter++; 
                else if (window[left] == need[left] - 1) counter--; 
            }

            if (counter == required_char) { 
                return true;
            }
        }
        return false;
    }
};