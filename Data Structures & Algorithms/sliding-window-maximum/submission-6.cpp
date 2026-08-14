class Solution{
public:
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k){
    std::deque<int> dq;
    std::vector<int> result;

    for(int right = 0; right < static_cast<int>(nums.size()); ++right){
        
        //Equivalent zu right - left + 1 in anderen Sliding Window Algorithmen
        if(!dq.empty() && dq.front() <= right - k){
            dq.pop_front();
        }

        //Entfernt von hinten die kleineren Zahlen da niemals max mehr sein können.
        while(!dq.empty() && nums[dq.back()] <= nums[right]){
            dq.pop_back();
        }

        dq.push_back(right);

        //Kleine aber feine Regel: Erst wenn Window erreicht return
        if(right >= k - 1){
            result.push_back(nums[dq.front()]);
        }

    }

    return result;
}
};