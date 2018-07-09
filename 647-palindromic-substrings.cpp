class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int totalCount = 0;

        for(int i = 0; i < n; i++) {
            int p, q;
            // 子串长度为奇数
            totalCount += 1;
            p = i-1, q = i+1;
            while(p >= 0 && q < n && s[p] == s[q]) {
                totalCount++;
                p--, q++;
            }
            // 子串长度为偶数
            p = i, q = i+1;
            while(p >= 0 && q < n && s[p] == s[q]) {
                totalCount++;
                p--, q++;
            }
        }
        return totalCount;
    }
};