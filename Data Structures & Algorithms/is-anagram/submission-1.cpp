class Solution {
public:
    bool isAnagram(string s, string t) {
          std::array<int, 26> buckets{};
  std::array<int, 26> buckett{};

  for(char c : s){
    buckets[c - 'a']++;
  }
  for(char c : t){
    buckett[c - 'a']++;
  }
  return buckets == buckett;
    }
};
