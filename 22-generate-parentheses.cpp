// 回溯法
typedef struct Node{
    int value;
    vector<Node*> next;
    Node(int val=0) : value(val), next(vector<Node*>()) {}
} Node;

class Solution {
public:
    vector<string> generateParenthesis(int n) {

        Node *root = new Node(-1);
        set<string> s;
        backtrace(root, n, s);

        vector<string> ans;
        ans.reserve(s.size());
        for(auto it = s.begin(); it != s.end(); it++)
            ans.push_back(*it);

        return ans;
    }
private:
    void backtrace(Node* root, int num, set<string>& ans) {
        if(num == 0) {
            string str = NodeToString(root);
            ans.insert(str);
            return;
        }

        Node *temp, *newNode = new Node;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            temp = q.front();
            q.pop();
            for(auto it = temp->next.begin(); it != temp->next.end(); it++)
                q.push(*it);

            temp->next.push_back(newNode);
            backtrace(root, num-1, ans);
            temp->next.pop_back();
        }
        return;
    }
    string NodeToString(Node* root) {
        string ret;
        if(root->value != -1)
            ret += "(";

        for(auto it = root->next.begin(); it != root->next.end(); it++)
            ret += NodeToString(*it);

        if(root->value != -1)
            ret += ")";
        return ret;
    }
};