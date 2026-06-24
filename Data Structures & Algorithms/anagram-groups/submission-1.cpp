struct Solution{
    struct Entry{
        std::array<uint8_t, 26> count;
        uint32_t index;
    }; 

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
        std::vector<Entry> group;
        group.reserve(strs.size());
        for(uint32_t i = 0; i < strs.size(); ++i){
            Entry e{};
            e.index = i;
            for(char c : strs[i]){
                e.count[c - 'a']++;
            }
            group.push_back(e);
        }

        std::sort(group.begin(), group.end(), [](const Entry& a, const Entry& b){
            return a.count < b.count;
        }); 

        std::vector<std::vector<std::string>> result;
        result.reserve(group.size());

        for(size_t i = 0; i < group.size();){ //ohne ++i!!
            size_t j = i;
            std::vector<std::string> anagrams;
            while(j < group.size() && group[i].count == group[j].count){
                anagrams.push_back(std::move(strs[group[j].index]));
                j++;
            }
            result.push_back(std::move(anagrams));
            i = j;
        }
        return result;
    };
};
