class Solution {
public:
    bool isValid(string s) {
        int size = s.size(), i;
        stack<char> st;

        for(i = 0; i < size; i++) {
            if(is_left(s[i])) {
                st.push(s[i]);
            }
            else if(!st.empty() && is_matched(st.top(), s[i])) {
                st.pop();
            } else {
                return false;
            }
        }

        if(!st.empty()) return false;
        return true;
    }
private:
    bool is_left(char ch) {
        return (ch == '{') || (ch == '(') || (ch == '[');
    }
    bool is_matched(char lhs, char rhs) {
        return (lhs == '{' && rhs == '}') || (lhs == '(' && rhs == ')') || (lhs == '[' && rhs == ']');
    }
};