class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0, size = nums.size(), count = 0;

        for(int i = 0; i < size; i++) {
            if(nums[i] == 1) {
                count +=1;
                continue;
            }
            if(count > 0) {
               if(count > max_count) {
                   max_count = count;
               }
               count = 0;
            }
        }
        if(count > max_count)
            max_count = count;
        return max_count;
    }
};