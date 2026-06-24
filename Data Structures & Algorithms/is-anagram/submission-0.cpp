class Solution {
public:
    bool isAnagram(std::string_view s, std::string_view t){
        if(s.length() != t.length()){
            return false;
        }

        std::unordered_map<char, size_t> seen;

        //lade den ersten String in den Hashtable
        for(auto c : s){
        auto it = seen.find(c);
        if(it != seen.end()){
           it->second = it->second + 1; 
        }
        else {
        seen.emplace(c, 1);
        }
        }

        //checke den zweiten String
        for(auto c : t){
            auto it = seen.find(c);
            if(it != seen.end() && it->second != 0){
                it->second = it->second - 1;
            }
            else{
                return false;
            }
        }
        return true;
        }
};
