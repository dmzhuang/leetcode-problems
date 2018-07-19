class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        const int maxn = 100001;
        if(n == 0 || n > maxn) return 0;
        int dp[maxn];
        dp[0] = nums[0];

        int sum = dp[0];
        for(int i = 1; i < n; i++) {
            if(dp[i-1] > 0)
                dp[i] = dp[i-1] + nums[i];
            else dp[i] = nums[i];
            if(dp[i] > sum)
                sum = dp[i];
        }
        return sum;
    }
};