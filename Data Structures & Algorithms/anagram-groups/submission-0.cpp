#include <ranges>

struct Solution{
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& str){
        std::unordered_map<std::string, std::vector<std::string>> anagrams;
        for(auto& s : str){
            std::string key = s;
            std::ranges::sort(key);
            anagrams[key].push_back(s);
        }
        return anagrams | std::views::values | std::ranges::to<std::vector>();
    }
};