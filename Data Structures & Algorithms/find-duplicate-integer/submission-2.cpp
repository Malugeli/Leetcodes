class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    std::array<bool, 10001> check;
    check.fill(false);
    for(auto num : nums){
        if(check[static_cast<size_t>( num )]){
            return num;
        }
        check[static_cast<size_t>( num )] = true;
    }
    return 0;
  }
};