const char *table[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        int len = words.size();
        for(int i = 0; i < len; i++) {
            string code = GetMorseCode(words[i]);
            s.insert(code);
        }
        return s.size();
    }
private:
    string GetMorseCode(const string& word) {
        string code;
        for(char c : word) {
            code += table[c-'a'];
        }
        return code;
    }
};