/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        _next = Traversal(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_next.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ans = _next.front(); _next.pop();
        return ans;
    }

private:
    TreeNode* CreateNode(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* newNode = new TreeNode(root->val);
        newNode->left = root->left;
        newNode->right = root->right;
        return newNode;
    }

    void DeleteNode(TreeNode* root) {
        if(!root) return;
        delete root;
    }

    queue<int> Traversal(TreeNode* root) {
        queue<int> ans;
        stack<TreeNode*> st;
        TreeNode *curr = NULL, *left = NULL, *right = NULL;
        curr = CreateNode(root);
        st.push(curr);

        while(!st.empty()) {
            while(st.top() != NULL) {
                curr = st.top(); st.pop();
                left = CreateNode(curr->left), right = CreateNode(curr->right);
                curr->left = curr->right = NULL;
                st.push(right); st.push(curr); st.push(left);
            }
            curr = st.top();
            st.pop();
            DeleteNode(curr);
            if(!st.empty()) {
                curr = st.top();
                st.pop();
                ans.push(curr->val);
                DeleteNode(curr);
            }
        }
        return ans;
    }

private:
    queue<int> _next;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */