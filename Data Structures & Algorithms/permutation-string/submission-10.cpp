class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::array<int, 26> need{};
        for(auto c : s1){
            ++need[static_cast<size_t>( c - 'a' )];
        }

        int matches{};

        for(auto i : need){
          if (i == 0) {
            ++matches;
          }
        }


        //also doch Left. Window ist statisch. Sprich right - left + 1 darf nie größer als s1.size() sein. Wenn doch muss left nachrücken
        std::array<int, 26> seen{}; 
        size_t left{};
        for(size_t right = 0; right < s2.size(); ++right){
            size_t index = static_cast<size_t>( s2[right] - 'a' );
            ++seen[index];
            if(seen[index] == need[index]) ++matches;
            else if(seen[index] -1 == need[index])
              --matches;

            size_t size = right - left +1;
            if(size > s1.size()){
                size_t left_index = static_cast<size_t> (s2[left] - 'a');
                --seen[left_index];
                if(seen[left_index] == need[left_index]) ++matches;
                else if(seen[left_index] + 1 == need[left_index]) --matches;
                ++left;
            }

            if(matches == 26){
                return true;
            }

        }

        return false;
    }
};