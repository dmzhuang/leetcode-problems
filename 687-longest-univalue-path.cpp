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
    int longestUnivaluePath(TreeNode* root) {
        int longest = 0;
        length_of_path_endswith_root(root, longest);
        return longest;
    }
    int length_of_path_endswith_root(TreeNode* root, int& longest) {
        int length = 0, across_length = 0, left_length = 0, right_length = 0;
        if(root) {
            if(root->left) {
                left_length = length_of_path_endswith_root(root->left, longest);
                if(root->val == root->left->val) {
                    length = left_length + 1;
                    across_length = length;
                }
            }
            if(root->right) {
                right_length = length_of_path_endswith_root(root->right, longest);
                if(root->val == root->right->val) {
                    length = std::max(length, right_length + 1);
                    across_length += right_length + 1;
                }
            }

        }
        longest = std::max(longest, across_length);
        return length;
    }
};