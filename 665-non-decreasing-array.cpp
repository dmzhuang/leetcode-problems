class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), count = 1, minLeft;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(count == 0) return false;
                if(i == 0 || nums[i-1] <= nums[i+1])
                    nums[i] = (i == 0) ? (nums[i] - 1) : nums[i-1];
                else
                    nums[i+1] = nums[i];
                count--;
            }
        }
        return true;
    }
};