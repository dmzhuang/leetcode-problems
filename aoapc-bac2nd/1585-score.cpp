#include <stdio.h>
#include <string.h>

#define local
const int maxn = 80;

int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    int t, score, n, i, count;
    char buf[maxn + 1];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", buf);
        n = strlen(buf);
        count = 0, score = 0;
        for(i = 0; i < n; i++) {
            if(buf[i] == 'O') count += 1;
            else count = 0;
            score += count;
        }
        printf("%d\n", score);
    }


    return 0;
}