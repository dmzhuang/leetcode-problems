class Solution {
private:
    void flipAndInvertRow(vector<int> &arr) {
        int size = arr.size(), len = arr.size() / 2;
        for(int i = 0; i < len; i++) {
            arr[i] = arr[i] + arr[size - 1 - i];
            arr[size - 1 - i] = arr[i] - arr[size - 1 - i];
            arr[i] = arr[i] - arr[size - 1 - i];
        }
        for(int i = 0; i < size; i++)
            arr[i] = 1 - arr[i];
    }

public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size();

        for(int i = 0; i < rows; i++)
            flipAndInvertRow(A[i]);

        return A;
    }
};