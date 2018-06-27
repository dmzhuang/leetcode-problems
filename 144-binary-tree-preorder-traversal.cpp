/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef struct ELEM {
    int rd;
    TreeNode* root;
    vector<int> ans;
    vector<int> v1;
    vector<int> v2;
}ELEM;

class Solution {
public:
    void printVector(const vector<int>& v) {
        int size = v.size();
        for(int i = 0; i < size; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        stack<ELEM> st;
        ELEM temp, elem;
        elem.rd = 3; elem.root = root;
        st.push(elem);

        do {
            while(st.top().root != NULL) {
                temp.rd = 1; temp.root = (st.top().root)->left;
                st.push(temp);
            }
            st.top().ans.clear();
            while(st.top().rd == 2) {
                temp = st.top(); st.pop();
                elem = st.top();
                elem.ans.clear();
                elem.ans.push_back((elem.root)->val);
                elem.ans.insert(elem.ans.end(), elem.v1.begin(), elem.v1.end());
                elem.ans.insert(elem.ans.end(), temp.ans.begin(), temp.ans.end());
                st.pop(); st.push(elem);
                //printVector(st.top().ans);
            }
            if(st.top().rd == 1) {
                temp = st.top(); st.pop();
                elem = st.top();
                elem.v1.assign(temp.ans.begin(), temp.ans.end());
                st.pop(); st.push(elem);
                //printVector(st.top().v1);
                temp.rd = 2; temp.root = (elem.root)->right; st.push(temp);
            }
        }while(st.top().rd != 3);

        return st.top().ans;
    }
};