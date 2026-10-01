#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];   // best[i-2]
        int prev1 = cost[1];   // best[i-1]

        for (int i = 2; i < n; ++i) {
            int cur = cost[i] + std::min(prev1, prev2);
            prev2 = prev1;
            prev1 = cur;
        }
        return std::min(prev1, prev2);   // von n-1 oder n-2 auf TOP
    }
};