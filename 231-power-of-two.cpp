// Given an integer, write a function to determine if it is a power of two.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n % 2) return false;
        return isPowerOfTwo(n / 2);
    }
};