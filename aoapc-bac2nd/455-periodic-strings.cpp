#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define local
const int max_len = 80;


int equalTo(const char s[], int p, int q, int len) {
    for(int i = 0; i < len; i++)
        if(s[p + i] != s[q + i])
            return 0;
    return 1;
}


int hasPeriod(const char str[], int period) {
    int num_period = strlen(str) / period;
    for(int i = 1; i < num_period; i++)
        if(!equalTo(str, 0, i * period, period))
            return 0;
    return 1;
}


int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    int t;
    char buf[max_len + 1];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", buf);
        int len = strlen(buf);
        int ans = len;
        for(int i = 1; i <= len; i++)
            if(len%i == 0 && hasPeriod(buf, i)) {
                ans = i; break;
            }
        printf("%d\n", ans);
        // if(t) printf("\n");
        if(t) puts("");
    }

    return 0;
}