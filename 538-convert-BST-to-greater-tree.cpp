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
    TreeNode* convertBST(TreeNode* root) {
        AddGreaterKeySum(root, 0);
        return root;
    }
private:
    int AddGreaterKeySum(TreeNode* root, int fromParent) {
        if(!root) return 0;

        int rightSum = 0, leftSum = 0, original_key = root->val;
        if(root->right);
            rightSum = AddGreaterKeySum(root->right, fromParent);
        root->val += rightSum + fromParent;
        if(root->left)
            leftSum = AddGreaterKeySum(root->left, original_key + rightSum + fromParent);
        return leftSum + original_key + rightSum;
    }
};