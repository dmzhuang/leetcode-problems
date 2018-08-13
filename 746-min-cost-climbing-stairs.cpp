class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        assert(n >= 2 && n <= 1000);
        const int maxn = 1000;
        int dp[maxn];
        dp[0] = cost[0]; dp[1] = cost[1];

        for(int i = 2; i < n; i++) {
            dp[i] = (dp[i-2] < dp[i-1]) ? dp[i-2] + cost[i] : dp[i-1] + cost[i];
        }

        return min(dp[n-2], dp[n-1]);
    }
};