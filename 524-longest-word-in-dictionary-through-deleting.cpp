class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for(string& str : d)
            //if(str < ans || ans.empty()) {
                if(isOk(str, s) && (str.length()>ans.length() || (str.length()==ans.length() && str<ans)))
                    ans = str;
            //}
        return ans;
    }
private:
    bool isOk(const string& str, const string& pattern) {
        int m = str.length(), n = pattern.length();
        for(int i = 0, j = 0; i < m; ++i) {
            while(j < n && str[i] != pattern[j]) j++;
            if(j >= n) return false;
            ++j;
        }
        return true;
    }
};