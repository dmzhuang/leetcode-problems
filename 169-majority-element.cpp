// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int bits = sizeof(int) * 8, size = nums.size();
        int count = 0, mask = 1, ret_val = 0;

        for(int i = 0; i < bits; i++) {
            count = 0;  // count保存所有元素第i位是1的数目
            for(int j = 0; j < size; j++) {
                if(mask & nums[j]) count++;
            }
            if(count > size / 2) // 当1的数目超过n/2，说明major number的该位是1；当1的数目<=size/2时，说明major number的该位是0
                ret_val |= mask;
            mask <<= 1;
        }
        return ret_val;
    }
};