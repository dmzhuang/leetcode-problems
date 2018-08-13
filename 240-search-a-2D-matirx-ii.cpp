class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        return search(matrix, 0, m-1, 0, n-1, target);
    }
private:
    bool search(vector<vector<int>>& matrix, int start_row, int end_row, int start_col, int end_col, int target) {
        if(end_row < start_row || end_col < start_col) {
            //cout << "fail" << endl;
            return false;
        }
        int mid_row = (start_row + end_row) / 2, mid_col = (start_col + end_col) / 2;
        //cout << "(" << mid_row << "," << mid_col << ")" << endl;
        if(matrix[mid_row][mid_col] == target) {
            //cout << "found" << endl;
            return true;
        }
        if(matrix[mid_row][mid_col] > target)
            return search(matrix, start_row, mid_row-1, start_col, mid_col-1, target) ||
                    search(matrix, start_row, mid_row-1, mid_col, mid_col, target) ||
                    search(matrix, mid_row, mid_row, start_col, mid_col-1, target) ||
                    //
                    search(matrix, start_row, mid_row-1, mid_col+1, end_col, target) ||
                    search(matrix, mid_row+1, end_row, start_col, mid_col-1, target);
        return search(matrix, start_row, mid_row, mid_col+1, end_col, target) ||
                search(matrix, mid_row+1, end_row, start_col, mid_col, target) ||
                search(matrix, mid_row+1, end_row, mid_col+1, end_col, target);
    }
};