class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i, j, k;

        i = 0;
        while(i < m) {
            for(k = i, j = 0; k < m-1 && j < n-1; k++, j++) {
                if(matrix[k][j] != matrix[k+1][j+1])
                    return false;
            }
            i++;
        }

        j = 1;
        while(j < n) {
            for(i = 0, k = j; i < m-1 && k < n-1; i++, k++) {
                if(matrix[i][k] != matrix[i+1][k+1])
                    return false;
            }
            j++;
        }

        return true;
    }
};