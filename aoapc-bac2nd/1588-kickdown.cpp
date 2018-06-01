#include <stdio.h>
#include <string.h>

#define local
// #define debug
const int maxn = 101;

// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define max(a, b) ((a) > (b) ? (a) : (b))


int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int isOk(const char str1[], int s1, int e1, const char str2[], int s2, int e2) {
    for(int i = s1, j = s2; i <= e1 && j <= e2; i++, j++)
        if(str1[i] - '0' + str2[j] - '0' > 3)
            return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    char s[maxn], t[maxn];
    while(scanf("%s", t) == 1) {
        scanf("%s", s);
        int m = strlen(s), n = strlen(t);
        #ifdef debug
        printf("------------------------------\n");
        printf("m = %d n = %d\n", m, n);
        #endif

        int p, q, left, right;
        int ans = m + n, length;
        for(p = 0; p < m + n; p++) {
            q = p + m - 1;
            left = max(p, m);
            right = min(q, m+n-1);
            #ifdef debug
            printf("p=%d q=%d [%d %d]\n", p, q, left, right);
            #endif
            // TODO
            length = max(q, m+n-1) - min(p, m) + 1;
            if(isOk(s, left-p, right-p, t, left-m, right-m)) {
                ans = min(ans, length);
            }
            #ifdef debug
            printf("interval %d\n", length);
            #endif
        }
        printf("%d\n", ans);
    }

    return 0;
}