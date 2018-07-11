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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int largestThisLayer = 0;
        int numThisLayer = 1, numToPop = 1, numNextLayer = 0;
        TreeNode* curr;

        while(!q.empty()) {
            curr = q.front();
            q.pop();
            numToPop--;
            if(numToPop == numThisLayer-1 || largestThisLayer < curr->val)
                largestThisLayer = curr->val;

            if(curr->left) {
                q.push(curr->left);
                numNextLayer++;
            }
            if(curr->right) {
                q.push(curr->right);
                numNextLayer++;
            }

            if(numToPop == 0) {
                ans.push_back(largestThisLayer);
                numThisLayer = numNextLayer;
                numToPop = numNextLayer;
                numNextLayer = 0;
            }
        }
        return ans;
    }
};