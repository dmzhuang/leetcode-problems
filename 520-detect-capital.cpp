class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int count = 0;
        for(char ch : word) {
            if(isupper(ch)) {
                count++;
            }
        }
        return count == 0 || count == n || ((count == 1) && isupper(word[0]));
    }
};