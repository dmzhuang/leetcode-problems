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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st;
        TreeNode *curr, *temp, *left, *right;
        curr = CreateNode(root);
        st.push(curr);

        while(!st.empty()) {
            while(st.top()->left) {
                curr = st.top();
                left = CreateNode(curr->left);
                curr->left = NULL;
                st.pop(); st.push(curr);
                st.push(left);
            }
            if(st.top()->right) {
                curr = st.top();
                right = CreateNode(curr->right);
                curr->right = NULL;
                st.pop(); st.push(curr);
                st.push(right);
            }
            if(!st.top()->left && !st.top()->right) {
                ans.push_back(st.top()->val);
                DeleteNode(st.top());
                st.pop();
            }
        }
        return ans;
    }

private:
    TreeNode* CreateNode(TreeNode *root) {
        if(!root) return NULL;
        TreeNode *newNode = new TreeNode(root->val);
        newNode->left = root->left;
        newNode->right = root->right;
        return newNode;
    }

    void DeleteNode(TreeNode* root) {
        if(!root) return;
        delete root;
    }
};