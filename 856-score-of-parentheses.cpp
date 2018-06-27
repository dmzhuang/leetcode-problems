typedef struct ELEM {
    int type; // 0 for (, 1 for numbers
    int value;
}ELEM;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<ELEM> s;
        ELEM temp;
        int size = S.size(), i;

        for(i = 0; i < size; i++) {
            if(S[i] == '(') {
                temp.type = 0; temp.value = '(';
                s.push(temp);
            } else if(s.top().type == 0) {
                temp.type = 1; temp.value = 1;
                s.pop();
                s.push(temp);
            } else {
                temp.type = 1; temp.value = s.top().value; s.pop();
                while(s.top().type != 0) {
                    temp.value += s.top().value;
                    s.pop();
                }
                temp.value *= 2;
                s.pop();
                s.push(temp);
            }
        }

        int ans = 0;
        while(!s.empty()) {
            ans += s.top().value;
            s.pop();
        }
        return ans;
    }
};