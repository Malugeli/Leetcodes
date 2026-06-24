class Solution {
std::unordered_set<int> test; 
    public:
    bool hasDuplicate(std::span<int> nums){
      for (int i : nums) {
        if (auto search = test.find(i); search != test.end()) {
          return true;
        } else {
          test.emplace(i);
        }
      }
      return false;
    }
};