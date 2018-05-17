#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 10000;


void whereIsTheMarble() {
    int n, q, x, a[maxn], kase = 0;
    while(scanf("%d%d", &n, &q) == 2 && n) {
        printf("CASE# %d:\n", ++kase);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a+n);
        while(q--) {
            scanf("%d", &x);
            int p = lower_bound(a, a+n, x) - a;
            printf("p = %d\n", p);
            if(p < n) printf("%d found at %d\n", x, p+1);
            else printf("%d not found\n", x);
        }
    }
}


void theBlocksProblem() {

}


// set
set<string> dict;
void andysFirstDictionary() {
    string s, buf;
    for(int i = 0; i < s.length(); i++) {
        if(isalpha(s[i])) s[i] = tolower(s[i]); else s[i] = ' ';
    }
    stringstream ss(s);
    while(ss >> buf) dict.insert(buf);

    for(set<string>::iterator it = dict.begin(); it != dict.end(); it++)
        cout << *it << endl;
}


// map
map<string, int> cnt;
vector<string> words;

string repr(const string& s) {
    string ans = s;
    for(int i = 0; i < s.length(); i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(), ans.end());
    return ans;
}

void anannagrams() {
    int n = 0;
    string s;
    while(cin >> s) {
        if(s[0] == '#') break;
        words.push_back(s);
        string r = repr(s);
        if(!cnt.count(r)) cnt[r] = 0;
        cnt[r] ++;
    }
    vector<string> ans;
    for(int i = 0; i < words.size(); i++)
        if(cnt[repr(words[i])] == 1) {
            ans.push_back(words[i]);
        }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}


// stack
typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set s) {
    if(IDcache.count(s)) return IDcache[s];
    Setcache.push_back(s);
    IDcache[s] = Setcache.size() - 1;
    return IDcache[s];
}

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

void theSetStackComputer() {
    stack<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if(op[0] == 'P') s.push(ID(Set()));
        else if(op[0] == 'D') s.push(s.top());
        else {
            Set s1 = Setcache[s.top()]; s.pop();
            Set s2 = Setcache[s.top()]; s.pop();
            Set newset;
            if(op[0] == 'U') set_union(ALL(s1), ALL(s2), INS(newset));
            if(op[0] == 'I') set_intersection(ALL(s1), ALL(s2), INS(newset));
            if(op[0] == 'A') {
                newset = s2;
                newset.insert(ID(s1));
            }
            s.push(ID(newset));
        }
        cout << Setcache[s.top()].size() << endl;
    }
}

// void theSetStackComputer() {
//     stack<Set> s;
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         string op;
//         cin >> op;
//         if(op[0] == 'P') s.push(Set());
//         if(op[0] == 'D') s.push(s.top());
//         else {
//             Set s1 = s.top(); s.pop();
//             Set s2 = s.top(); s.pop();
//             Set newset;
//             if(op[0] == 'U')
//                 set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), newset, newset.begin());
//             if(op[0] == 'I')
//                 set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), newset, newset.begin());
//             if(op[0] == 'A') {
//                 newset = s2;
//                 // newset.insert(s1);
//             }
//             s.push(newset);
//         }
//         cout << s.top().size() << endl;
//     }
// }



int main() {
    // whereIsTheMarble();
    return 0;
}
