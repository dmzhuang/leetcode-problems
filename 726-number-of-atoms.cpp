class Solution {
public:
    using Item = struct item{
        int type; // 0 for (, 1 for Elem+digit, -1 for invalid
        string element;
        int count;
    };

    string countOfAtoms(string formula) {
        queue<string> q;
        Tokenize(formula, q);

        vector<Item> v;
        Item item;
        while(!q.empty()) {
            string token = q.front(); q.pop();
            cout << token << endl;
            if(token.find("(") != string::npos) {           // 当前为左括号(
                item.type = 0;
                v.push_back(item);
            } else if(token.find(")") == string::npos) {    // 当前为[A-Z][a-z]*[0-9]*格式
                item.type = 1;
                ExtractElementToken(token, item);
                v.push_back(item);
            } else {                                        // 当前为)[0-9]*格式
                int scale = ExtractRightBracketToken(token);
                auto it = v.rbegin();
                for(; it->type!=0; it++) {
                    if(it->type == 1)
                        it->count *= scale;
                }
                it->type = -1;
            }
        }

        map<string, int> m_map;
        int size = v.size(), i;
        for(i = 0; i < size; i++) {
            if(v[i].type == 1) {
                if(m_map.find(v[i].element) == m_map.end()) {
                    m_map.insert(std::pair<string, int> (v[i].element, 0));
                }
                m_map[v[i].element] += v[i].count;
                cout << v[i].element << " " << v[i].count << endl;
            }
        }

        string ans;
        for(auto it = m_map.begin(); it != m_map.end(); it++) {
            if(it->second == 1)
                ans = ans + it->first;
            else
                ans = ans + it->first + to_string(it->second);
        }
        return ans;
    }

    void ExtractElementToken(const string& token, Item& item) {
        int len = token.length(), i = 0;
        while(i < len && isalpha(token[i])) {
            i++;
        }
        if(i >= len) {
            item.element = token.substr(0);
            item.count = 1;
        } else {
            item.element = token.substr(0, i);
            item.count = stoi(token.substr(i));
        }
    }

    int ExtractRightBracketToken(const string& token) {
        if(token.length() > 1) {
            return stoi(token.substr(1));
        }
        return 1;
    }

    void Tokenize(const string& formular, queue<string>& q) {
        int len = formular.length(), i;

        for(i = 0; i < len; ) {
            if(formular[i] == '(') {
                q.push("(");
                i++;
            } else if(formular[i] == ')') {
                int j = i+1;
                while(j < len && isdigit(formular[j])) {
                    j++;
                }
                q.push(formular.substr(i, j-i));
                i = j;
            } else if(isupper(formular[i])) {
                int j = i+1;
                while(j < len && (islower(formular[j]) || isdigit(formular[j]))) {
                    j++;
                }
                q.push(formular.substr(i, j-i));
                i = j;
            } else {
                cout << "Tokenize error" << endl;
                break;
            }
        }
        return;
    }
};