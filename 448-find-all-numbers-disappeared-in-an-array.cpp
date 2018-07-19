class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> v(n+1, 0);
        for(int i : nums) {
            v[i] = 1;
        }
        for(int i = 1; i <= n; i++)
            if(v[i] == 0)
                ans.push_back(i);
        return ans;
    }
};