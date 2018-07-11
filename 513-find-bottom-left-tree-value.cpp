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
    int findBottomLeftValue(TreeNode* root) {
        assert(root != NULL);
        queue<TreeNode*> q;
        q.push(root);
        int numThisLayer = 1, numNextLayer = 0;
        int ans = root->val;
        TreeNode* curr;

        while(!q.empty()) {
            // cout << numThisLayer << " " << numNextLayer << endl;
            curr = q.front();
            q.pop();
            numThisLayer--;

            if(curr->left) {
                q.push(curr->left);
                numNextLayer++;
                if(numNextLayer == 1)
                    ans = curr->left->val;
            }

            if(curr->right) {
                q.push(curr->right);
                numNextLayer++;
                if(numNextLayer == 1)
                    ans = curr->right->val;
            }

            if(numThisLayer == 0) {
                numThisLayer = numNextLayer;
                numNextLayer = 0;
            }
        }
        return ans;
    }
};