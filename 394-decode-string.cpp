class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans;
        int size = s.length(), i = 0, start_pos, end_pos;

        for(; i < size; i++) {
            if(s[i] != ']') {
                st.push(s[i]);
            } else {
                // get encoded string
                string encoded_string;
                while(!st.empty() && st.top() != '[' && !isdigit(st.top())) {
                    encoded_string.insert(0, 1, st.top());
                    st.pop();
                }
                if(!st.empty() && st.top() == '[')
                    st.pop();
                // get repeated times
                string times;
                while(!st.empty() && isdigit(st.top())) {
                    times.insert(0, 1, st.top());
                    st.pop();
                }
                int repeat_times = stoi(times);
                int len = encoded_string.length();
                while(repeat_times--) {
                    for(int j = 0; j < len; j++)
                        st.push(encoded_string[j]);
                }
            }
        }

        while(!st.empty()) {
            ans = string(1, st.top()) + ans;
            st.pop();
        }
        return ans;
    }
};