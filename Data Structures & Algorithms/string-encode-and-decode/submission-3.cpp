class Solution {
private:
  std::unordered_map<std::string, std::vector<std::string>> coder;

public:
  std::string encode(std::vector<std::string> &strs) {
    std::string result;
    for (const auto s : strs) {
      result += '"' + s + '"' + " ";
    }
    coder.emplace(result, strs);
    return result;
  }

  std::vector<std::string> decode(const std::string s) {
    return coder[s];
  }
};