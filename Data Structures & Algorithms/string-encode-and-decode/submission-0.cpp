class Solution {
private:
  std::unordered_map<std::string, std::vector<std::string>> coder;

public:
  std::string encode(std::vector<std::string> &strs) {
    std::string result;
    for (auto s : strs) {
      result += '"' + s + '"' + " ";
    }
    coder.emplace(result, strs);
    return result;
  }

  std::vector<std::string> decode(std::string s) {
    return coder[s];
  }
};