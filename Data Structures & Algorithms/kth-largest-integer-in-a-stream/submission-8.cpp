class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) {
      for(auto num : nums){
         k_.push(num);
      }
      size = static_cast<size_t>( k );
    }
    
    int add(int val) {
      k_.push(val);
      while(k_.size() > size){
         k_.pop();
      }
      return k_.top();
    }

private:
std::priority_queue<int, std::vector<int>, std::greater<int>> k_;
size_t size;
};