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
    string tree2str(TreeNode* t) {
        string result = ToString(t);
        return result;
    }
private:
    string ToString(TreeNode* t) {
        string str;
        if(!t) return str;
        str = to_string(t->val);

        if(t->left && t->right) {
            str += "(" + ToString(t->left) + ")" + "(" + ToString(t->right) + ")";
        } else if(t->left) {
            str += "(" + ToString(t->left) + ")";
        } else if(t->right) {
            str += "()(" + ToString(t->right) + ")";
        } else {
        }

        return str;
    }
};