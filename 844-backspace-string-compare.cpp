class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<int> ss, st;
        int len, i;

        len = S.length();
        for(i = 0; i < len; i++) {
            if(S[i] != '#') ss.push(S[i]);
            else if(!ss.empty()) ss.pop();
        }
        len = T.length();
        for(i = 0; i < len; i++) {
            if(T[i] != '#') st.push(T[i]);
            else if(!st.empty()) st.pop();
        }

        while(!ss.empty() && !st.empty()) {
            if(ss.top() != st.top()) return false;
            ss.pop(); st.pop();
        }
        if(ss.empty() && st.empty()) return true;
        return false;
    }
};