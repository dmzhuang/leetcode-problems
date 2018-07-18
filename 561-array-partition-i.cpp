class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, size = nums.size();
        for(int i = 0; i < size; i+=2)
            sum += nums[i];
        return sum;
    }
};