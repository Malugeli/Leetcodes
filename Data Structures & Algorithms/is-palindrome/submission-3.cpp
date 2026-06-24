#include <ranges>
#include <algorithm>

struct Solution{
    bool isPalindrome(std::string s){
        auto palindrome = s | std::ranges::views::filter([](char c){ return isalnum(c);}) | std::ranges::views::transform([](char c){return tolower(c);}) | std::ranges::to<std::string>();
        return std::ranges::equal(palindrome, std::views::reverse(palindrome));
    }
};