// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Example 1:

// Input: [2,2,3,2]
// Output: 3
// Example 2:

// Input: [0,1,0,1,0,1,99]
// Output: 99


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits = sizeof(int) * 8, size = nums.size();
        int ret_val = 0, sum = 0;

        for(int i = 0; i < bits; i++) {
            sum = 0;
            for(int j = 0; j < size; j++) {
                if((nums[j] >> i) & 1)
                    sum++;
            }
            if(sum % 3)
                ret_val |= (1 << i);
        }
        return ret_val;
    }
};