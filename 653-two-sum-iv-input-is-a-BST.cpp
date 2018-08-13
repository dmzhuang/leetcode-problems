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
    bool findTarget(TreeNode* root, int k) {
        vector<int> values;
        InorderTraversal(root, values);

        return TwoSum(values, k);
    }
    bool TwoSum(const vector<int>& nums, int target) {
        int p = 0, q = nums.size() - 1;

        while(p < q) {
            while(q > p && nums[p]+nums[q] > target) q--;
            if(q <= p) return false;
            if(nums[p]+nums[q] == target) return true;
            p++;
        }
        return false;
    }
    void InorderTraversal(TreeNode* root, vector<int>& values) {
        if(!root) return;
        if(root->left) InorderTraversal(root->left, values);
        values.push_back(root->val);
        if(root->right) InorderTraversal(root->right, values);
    }
};