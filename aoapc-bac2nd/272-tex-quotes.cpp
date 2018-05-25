#include <cstdio>

#define local

int main() {
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif

    /*const int maxn = 1000;
    char buf[maxn + 1] = {'\0'};
    while(fgets(buf, maxn, stdin)) {
        printf("%s", buf);
    }*/

    int c, q = 1;
    while((c = getchar()) != EOF) {
        if(c == '"') {
            printf("%s", q ? "``": "''");
            q = !q;
        }else 
            printf("%c", c);
    }

    return 0;
}
