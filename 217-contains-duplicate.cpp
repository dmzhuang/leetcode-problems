class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return containsDuplicateBit(nums, 0);
    }

private:
    bool containsDuplicateBit(const vector<int>& nums, int nbit) {
        if(nums.size() <= 1) return false;
        if(nbit >= sizeof(int) * 8) return true;
        vector<int> zero, one;
        //while(nbit < sizeof(int) * 8) {
            for(int i : nums) {
                if((i >> nbit) & 1)
                    one.push_back(i);
                else
                    zero.push_back(i);
            }
        //}
        bool ans = false;
        if(zero.size() > 0)
            ans |= containsDuplicateBit(zero, nbit+1);
        if(one.size() > 0)
            ans |= containsDuplicateBit(one, nbit+1);
        return ans;
    }
};