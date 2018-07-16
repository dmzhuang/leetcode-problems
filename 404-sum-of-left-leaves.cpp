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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(!root) return sum;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;

        while(!q.empty()) {
            curr = q.front();
            q.pop();

            if(curr->left) {
                q.push(curr->left);
                if(!curr->left->left && !curr->left->right)
                    sum += curr->left->val;
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }

        return sum;
    }
};