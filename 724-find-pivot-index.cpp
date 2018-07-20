class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int num : nums)
            sum += num;

        int sumToLeft = 0, pivotIndex = -1;
        for(int i = 0; i < n; i++) {
            if(sum - nums[i] == sumToLeft * 2) {
                pivotIndex = i;
                break;
            }
            sumToLeft += nums[i];
        }
        return pivotIndex;
    }
};