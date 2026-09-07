class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    size_t slow = 0;
    size_t fast = 0;
    
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while(fast != slow);

    slow = 0;

    while(fast != slow){
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
  }
};