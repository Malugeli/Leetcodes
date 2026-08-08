class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : size(k) { //Initialisierungsliste vergessen!
            for(auto num : nums){
                add(num);
            }
        }
    
    int add(int val) { 
        min_heap.push(val);
        while(static_cast<int>( min_heap.size() ) > size){
            min_heap.pop();
        }
        return min_heap.top();
    }

private:
std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
int size; 
};
