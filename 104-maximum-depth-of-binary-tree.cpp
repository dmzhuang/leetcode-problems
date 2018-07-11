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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(!root) return depth;
        queue<TreeNode*> q;
        q.push(root);
        int numToPop = 1, numNextLayer = 0;
        TreeNode* curr;

        while(!q.empty()) {
            curr = q.front();
            q.pop();
            numToPop--;

            if(curr->left) {
                q.push(curr->left);
                numNextLayer++;
            }
            if(curr->right) {
                q.push(curr->right);
                numNextLayer++;
            }

            if(numToPop == 0) {
                depth++;
                numToPop = numNextLayer;
                numNextLayer = 0;
            }
        }
        return depth;
    }
};