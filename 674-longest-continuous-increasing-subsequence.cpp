class Solution {
private:
    static const int maxn = 10000;
    int dp[maxn];
public:
    int findLengthOfLCIS(vector<int>& nums) {
        assert(nums.size() <= maxn);
        int n = nums.size(), length = 1;
        if(n == 0) return 0;
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;
            else dp[i] = 1;
            if(dp[i] > length)
                length = dp[i];
        }

        return length;
    }
};