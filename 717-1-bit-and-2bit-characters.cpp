class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 0) return true;
        return isValidString(bits, bits.size() - 1);
    }
private:
    bool isValidString(vector<int>& bits, int n) {
        if(n == 0) return true;
        if(n == 1) return bits[0] == 0;
        if(n == 2) return bits[0] != 0 || bits[1] != 1;
        if(bits[n-1] == 1)
            return bits[n-2] == 1 && isValidString(bits, n-2);
        return isValidString(bits, n-1) || isValidString(bits, n-2);
    }
};