class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;  // dp[i-2], anfangs dp[0]
        int prev1 = 1;  // dp[i-1], anfangs dp[1]
        for (int i = 2; i <= n; ++i) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};