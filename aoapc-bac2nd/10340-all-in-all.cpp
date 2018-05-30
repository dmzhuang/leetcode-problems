#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define local
// #define debug


const int maxn = 100001;

char s[maxn], t[maxn];


int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    while(scanf("%s%s", s, t) == 2) {
        int len_s = strlen(s), len_t = strlen(t);
        #ifdef debug
        printf("pass 1\n");
        #endif
        int ans = 1;
        int j = 0;
        for(int i = 0; i < len_s; i++) {
            while(j<len_t && t[j]!=s[i]) j++;
            if(j >= len_t) {
                ans = 0; break;
            }
            j++;
        }
        printf("%s\n", ans ? "Yes" : "No");
        #ifdef debug
        printf("pass 2\n");
        #endif
    }


    return 0;
}