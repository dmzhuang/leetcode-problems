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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        double sumThisLayer = 0.0;
        int numThisLayer = 1, numToPop = 1, numNextLayer = 0;
        TreeNode* curr;

        while(!q.empty()) {
            curr = q.front();
            q.pop();
            sumThisLayer += double(curr->val);
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
                ans.push_back(sumThisLayer / numThisLayer);

                numThisLayer = numNextLayer;
                sumThisLayer = 0.0;
                numToPop = numNextLayer;
                numNextLayer = 0;
            }
        }
        return ans;
    }
};