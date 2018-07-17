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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        GetSum(root, tilt);
        return tilt;
    }
    int GetSum(TreeNode* root, int& tilt) {
        if(!root) {
            return 0;
        }
        int leftSum = 0, rightSum = 0;
        if(root->left)
            leftSum = GetSum(root->left, tilt);
        if(root->right)
            rightSum = GetSum(root->right, tilt);
        tilt += fabs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};