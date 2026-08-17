class Solution{
    public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        //die machen das Indexbasiert

        std::deque<int> sorted;
        std::vector<int> result;
        for(int i = 0; i < static_cast<int>( nums.size() ); ++i){
            //wenn Fenster zu groß entferne das vorderste Element
            if(!sorted.empty() && sorted.front() <= i - k){
                sorted.pop_front();
            }

            //Entferne von hinten alles was kleiner als die neue Zahl ist
            while(!sorted.empty() && nums[sorted.back()] <= nums[i]){
                sorted.pop_back();
            }
            //Mach die neue Zahl rein
            sorted.push_back(i);

            if(i >= k - 1){
                result.push_back(nums[sorted.front()]);
            }
        }
        return result;
    }
};