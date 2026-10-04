class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::array<int, 128> ascii;
    ascii.fill(-1);
    int left{};
    int answer{};
    for (int right = 0; right < s.size(); ++right) {
      int index = ascii[s[right]];
      if (index >= left) {
        left = index + 1;
      }
      ascii[s[right]] = right;
      answer = std::max(answer, right - left + 1);
    }
    return answer = 0 ? s.size() : answer;
  }
};
