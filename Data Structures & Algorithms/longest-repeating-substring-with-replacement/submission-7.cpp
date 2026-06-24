struct Solution {
  int characterReplacement(std::string s, int k) {
    int left = 0;
    int max_freq = 0;
    std::array<int, 26> characters{};

    for (int right = 0; right < std::ssize(s); ++right) {
      characters[s[right] - 'A']++;
      max_freq = std::max(characters[s[right] - 'A'], max_freq);
      if ((right - left + 1) - max_freq > k) {
        characters[s[left] - 'A']--;
        left++;
      }
    }
    return std::ssize(s) - left;
  }
};