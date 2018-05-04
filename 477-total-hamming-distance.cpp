// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Now your job is to find the total Hamming distance between all pairs of the given numbers.

// Example:
// Input: 4, 14, 2

// Output: 6

// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
// showing the four bits relevant in this case). So the answer will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
// Note:
// Elements of the given array are in the range of 0 to 10^9
// Length of the array will not exceed 10^4.


// C(N,2) = C(m,2) + C(n,2) + C(n,1)*C(m,1)
// where m + n = N
class Solution {
public:
    int totalHammingDistance(vector<int> nums) {
        int size = nums.size(), bits = sizeof(int) * 8;
        int ret_val = 0, count;

        for(int i = 0; i < bits; i++) {
            count = 0;
            for(int j = 0; j < size; j++) {
                if((nums[j] >> i) & 1)
                    count +=1;
            }
            ret_val += count * (size - count);
        }
        return ret_val;
    }
};