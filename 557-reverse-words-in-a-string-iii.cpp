class Solution {
public:
    string reverseWords(string s) {
        int start_index = 0, end_index = s.find(" ");
        string substring, revSubstring;

        // split
        while(start_index < s.length() && end_index != string::npos) {
            substring = s.substr(start_index, end_index-start_index);
            // cout << substring << endl;

            revSubstring = reverseString(substring);
            s.replace(start_index, end_index-start_index, revSubstring);
            // cout << s << endl;

            start_index = end_index + 1;
            end_index = s.find(" ", start_index);
        }
        if(start_index < s.length())
            substring = s.substr(start_index, s.length()-start_index);
        revSubstring = reverseString(substring);
        s.replace(start_index, end_index-start_index, revSubstring);
        // cout << substring << endl;
        return s;
    }
    string reverseString(const string& s) {
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