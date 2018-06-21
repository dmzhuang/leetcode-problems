#include <iostream>
#include <stack>

using namespace std;

// 火车进出站问题
// 思考：
// 若入栈的顺序为1,2,3,4
// 那么出栈的顺序可以有哪些
// 对于输出序列i,j,k，若存在pj<pk<pi
// 则输出序列是否合法？

int is_valid_train_sequence(int a[], int n) {
    stack<int> s_a, s_station;
    for(int i = n; i >= 1; i--)
        s_a.push(i);

    int curr;
    for(int i = 0; i < n; i++) {
        curr = a[i];
        #ifdef debug
        cout << "curr " << curr << endl;
        #endif
        if(!s_station.empty() && s_station.top() == curr) {
            s_station.pop();
            continue;
        }
        while(!s_a.empty() && s_a.top() != curr) {
            s_station.push(s_a.top());
            s_a.pop();
        }
        if(s_a.empty()) {
            return 0;
        } else {
            s_a.pop();
            continue;
        }
    }
    return 1;
}

const int maxn = 1000;
int a[maxn];

int main(int argc, char const *argv[])
{
    int n;
    while(cin >> n && n) {
        while(cin >> a[0] && a[0]) {
            for(int i = 1; i < n; i++)
                cin >> a[i];
            cout << is_valid_train_sequence(a, n) << endl;
        }
    }
    return 0;
}