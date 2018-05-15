class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        if(m <= 0) return nums;
        int n = nums[0].size();
        if(m * n != r * c)
            return nums;

        vector<vector<int> > ans;
        for(int i = 0; i < r; i++) {
            vector<int> tmp;
            for(int j = 0; j < c; j++) {
                int k = i * c + j;
                tmp.push_back(nums[k / n][k % n]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};