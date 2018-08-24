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
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        get_number_of_nodes(root, is_balanced);
        return is_balanced;
    }
    int get_number_of_nodes(TreeNode* root, bool& is_balanced) {
        int depth = 0, left_depth = 0, right_depth = 0;
        if(root) {
            depth = 1;
            if(root->left) {
                left_depth = get_number_of_nodes(root->left, is_balanced);
                if(!is_balanced)
                    return 0;
            }
            if(root->right) {
                right_depth = get_number_of_nodes(root->right, is_balanced);
                if(!is_balanced)
                    return 0;
            }
            if(std::abs(left_depth - right_depth) > 1) {
                is_balanced = false;
                return 0;
            }
            depth += std::max(left_depth, right_depth);
        }
        return depth;
    }
};