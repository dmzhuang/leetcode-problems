/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string> > arr2d;
        int m = GetHeight(root);
        if(m == 0)
            return arr2d;

        int n = (1<<m) - 1;
        cout << m << "," << n << endl;

        vector<string> row;
        row.reserve(n);
        for(int i = 0; i < n; i++)
            row.push_back("");
        for(int i = 0; i < m; i++)
            arr2d.push_back(row);

        print(root, arr2d, 0, 0, n);

        return arr2d;
    }
private:
    void print(TreeNode* root, vector<vector<string> >&arr2d, int row, int start_col, int end_col) {
        if(end_col <= start_col) return;
        if(!root) return;
        int mid = (end_col + start_col) / 2;
        arr2d[row][mid] = to_string(root->val);
        print(root->left, arr2d, row+1, start_col, mid);
        print(root->right, arr2d, row+1, mid+1, end_col);
        return;
    }
public:
    int GetHeight(TreeNode* root) {
        if(!root) return 0;

        int height = 0;
        queue<TreeNode*> q;
        q.push(root);
        int numToPop = 1, numAdded = 0;

        TreeNode *curr;
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            numToPop--;

            if(curr->left) {
                q.push(curr->left);
                numAdded++;
            }
            if(curr->right) {
                q.push(curr->right);
                numAdded++;
            }

            if(numToPop == 0) { // 本层访问结束
                height++;
                numToPop = numAdded;
                numAdded = 0;
            }
        }

        return height;
    }
};