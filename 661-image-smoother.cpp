class Solution {
private:
    int delta_x[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int delta_y[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.size() == 0) return M;
        vector<vector<int> > ans(M.begin(), M.end());
        int m = M.size(), n = M[0].size();

        int i, j, k, sum, count;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                sum = 0;
                count = 0;
                for(k = 0; k < 9; k++) {
                    int new_i = i + delta_x[k], new_j = j + delta_y[k];
                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                        sum += M[new_i][new_j];
                        count++;
                    }
                }
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};