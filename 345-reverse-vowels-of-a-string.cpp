class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length(), i = 0, j = n - 1;
        while(i < j) {
            while(i < n && !is_vowel(s[i])) i++;
            while(j >= 0 && !is_vowel(s[j])) j--;
            if(i < n && j >= 0 && i < j) {
                swap(s, i, j);
                ++i, --j;
            }
        }
        return s;
    }
    bool is_vowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    void swap(string& s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
};