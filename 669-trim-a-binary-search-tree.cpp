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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode *result = NULL;
        if(root) {
            TreeNode* left = trimBST(root->left, L, R);
            TreeNode* right = trimBST(root->right, L, R);
            if((root->val >= L) && (root->val <= R)) {  // 根结点保留
                result = new TreeNode(root->val);
                result->left = left;
                result->right = right;
            } else if(right == NULL) {  // 根结点需要删除，且右结点为空，则取左结点
                result = left;
            } else if(left == NULL) {   // 根结点需要删除，且左结点为空，则取右结点
                result = right;
            } else {                    // 根结点需要删除，且左右结点都非空
                int min_of_right = 0;
                right = RemoveMinimumFromBST(right, min_of_right);
                result = new TreeNode(min_of_right);
                result->left = left;
                result->right = right;
            }
        }
        return result;
    }
private:
    // 从root中删除最小元素，元素值保存在value中，函数返回删除后的树的根结点
    // 对于只有一个元素的root，删除后应该返回NULL
    TreeNode* RemoveMinimumFromBST(TreeNode* root, int& value) {
        if(!root) return NULL;
        TreeNode *curr = root, *parent = NULL, *ret;
        while(curr->left) {
            parent = curr;
            curr = curr->left;
        }
        value = curr->val;
        if(curr == root) {
            ret = root->right;
            root->right = NULL;
            return ret;
        }
        parent->left = NULL;
        return root;
    }
};