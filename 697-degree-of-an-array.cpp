class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        const int maxn = 50000;
        int freq[maxn] = {0}, first[maxn] = {-1}, last[maxn] = {-1};
        memset(freq, 0, maxn);
        memset(first, -1, maxn);
        memset(last, -1, maxn);

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            freq[nums[i]] += 1;
            if(first[nums[i]] == -1)
                first[nums[i]] = i;
            last[nums[i]] = i;
        }

        int degree = 0;
        int length = -1;
        for(int i = 0; i < maxn; i++) {
            if(freq[i] > degree) {
                degree = freq[i];
                length = last[i] - first[i] + 1;
            } else if(freq[i] == degree && last[i] - first[i] + 1 < length) {
                length = last[i] - first[i] + 1;
            }
        }
        return length;
    }
};