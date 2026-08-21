class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> max_heap(nums.begin(), nums.end());

        for(int i = 0; i < k-1; ++i){
            max_heap.pop();
        }
        return max_heap.top();
    }
};