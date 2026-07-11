class Solution{
    public:
    int minEatingSpeed(std::vector<int>& piles, int h){
        int low = 1;
        int high = *std::ranges::max_element(piles);

        auto check = [&](int k){
            int total_hours = 0;
            for(auto pile : piles){
              total_hours += (pile + k - 1) / k; // ist das selbe wie ceil (pile / k) aber kleiner Flex
            }
            if(total_hours <= h){
                return true;
            }
            return false;
        };

        while(low < high){
            int mid = std::midpoint(low, high);
            if(check(mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};