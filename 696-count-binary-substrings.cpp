class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), count = 0;

        for(int i = 0; i < n-1; i++) {
            int p = i, q = i+1;
            int left = s[p] - '0', right = s[q] - '0';
            if(left + right != 1) continue;
            while(p >= 0 && q < n) {
                if(s[p] - '0' == left && s[q] - '0' == right)
                    count++;
                else break;
                p--, q++;
            }
        }
        return count;
    }
};