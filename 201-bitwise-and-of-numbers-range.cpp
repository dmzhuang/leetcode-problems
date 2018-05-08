// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

// Example 1:

// Input: [5,7]
// Output: 4
// Example 2:

// Input: [0,1]
// Output: 0


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int num_of_bits = sizeof(int) * 8;
        int length = n - m + 1;
        int bit_of_m, bit_of_n;
        int ret_val = 0;

        for(int i = 0; i < num_of_bits; i++) {
            bit_of_m = (m >> i) & 1;
            bit_of_n = (n >> i) & 1;
            if((bit_of_m & bit_of_n) && (length <= pow(2,i)))
                ret_val |= (1 << i);
        }
        return ret_val;
    }
};