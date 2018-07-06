class Solution {
public:
    string reverseString(string s) {
        const char *cstr = s.c_str();
        if(!cstr) return s;
        char *p = new char[strlen(cstr)+1];
        strcpy(p, cstr);
        int len = strlen(p);
        p[len] = '\0';
        for(int i = 0; i < len/2; i++) {
            p[i] = p[i] ^ p[len-1-i];
            p[len-1-i] = p[i] ^ p[len-1-i];
            p[i] = p[i] ^ p[len-1-i];
        }
        string ans(p);
        delete[] p;
        return ans;
    }
};