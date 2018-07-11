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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        TreeNode *ans = constructTree(nums, 0, n);
        return ans;
    }
private:
    // 针对向量nums的区间[start, end)构建最大树
    TreeNode *constructTree(const vector<int>& nums, int start, int end) {
        if(end <= start) return NULL;
        int maxPos = findMaximum(nums, start, end);

        TreeNode *leftSubtree = constructTree(nums, start, maxPos);
        TreeNode *rightSubtree = constructTree(nums, maxPos+1, end);
        TreeNode *root = new TreeNode(nums[maxPos]);
        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }

    int findMaximum(const vector<int>& nums, int start, int end) {
        int max = nums[start], index = start;
        for(int i = start+1; i < end; i++)
            if(nums[i] > max) {
                max = nums[i];
                index = i;
            }
        return index;
    }
};