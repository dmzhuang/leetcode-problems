class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m <= 0) return false;
        int n = matrix[0].size();

        for(int j = 0; j < n; j++) {
            // int col = j;
            int tmp = ~0;
            for(int i = m-1, k = j; i >= 0 && k >= 0; i--, k--) {
                tmp ^=matrix[i][k];
                if(tmp != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};