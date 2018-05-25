/*
 * 1:多项式加法
 */

// #include <iostream>
#include <map>
// #include <algorithm>
#include <cstdio>

using namespace std;


#define local


void print_map(map<int, int>& m) {
    map<int, int>::reverse_iterator it;
    for(it = m.rbegin(); it != m.rend(); it++) {
        if(it->second != 0) {
            if(it != m.rbegin())
                printf(" ");
            printf("[%d %d]", it->second, it->first);
        }
    }
    printf("\n");
}


void initialze_map(map<int, int>& m) {
    map<int, int>::iterator it;
    int x, y;
    while(scanf("%d%d", &x, &y) == 2 && y >= 0) {
        it = m.find(y);
        if(it == m.end())
            m[y] = x;
        else
            m[y] = m[y] + x;
    }
    return;
}


int main() {
    #ifdef local
        freopen("data.in", "r", stdin);
        // freopen("data.out", "w", stdout);
    #endif

    int kase;
    scanf("%d", &kase);

    while(kase--) {
        map<int, int> m;

        initialze_map(m);
        initialze_map(m);
        print_map(m);
    }

    return 0;
}