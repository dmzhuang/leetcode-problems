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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *t3 = NULL;
        if(t1 || t2) {
            t3 = mergeNode(t1, t2);
            t3->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
            t3->right = mergeTrees(t1 ? t1->right: NULL, t2 ? t2->right : NULL);
        }
        return t3;
    }
private:
    TreeNode* mergeNode(TreeNode* t1, TreeNode* t2) {
        TreeNode *tsum = new TreeNode(0);
        if(t1) tsum->val += t1->val;
        if(t2) tsum->val += t2->val;
        return tsum;
    }
};