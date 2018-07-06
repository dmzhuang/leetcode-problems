class Solution {
public:
    string toGoatLatin(string s) {
        int start_index = 0, end_index = s.find(" ");
        string substring, revSubstring;

        // split
        int k = 1;
        while(start_index < s.length() && end_index != string::npos) {
            Replace(s, start_index, end_index-start_index, k);
            start_index = end_index + 1 + 2 + k;
            end_index = s.find(" ", start_index);
            k++;
        }
        if(start_index < s.length())
            Replace(s, start_index, end_index-start_index, k);

        return s;
    }

    void Replace(string& s, int pos, int len, int app_num) {
        string word = s.substr(pos, len);
        string newstring;
        if(is_vowel(word[0])) {
            newstring = word + "ma";
        } else {
            newstring = word.substr(1) + string(1, word[0]) + "ma";
        }
        newstring += string(app_num, 'a');
        // cout << word << " => " << newstring << endl;
        s.replace(pos, len, newstring);
        // cout << s << endl;
    }

    bool is_vowel(char c) {
        char lower = tolower(c);
        return (lower == 'a') || (lower == 'e') || (lower == 'i') || (lower == 'o') || (lower == 'u');
    }
};