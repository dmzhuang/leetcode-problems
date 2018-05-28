#include <stdio.h>
#include <string.h>

#define local
const int maxn = 100;


int is_smaller_than(const char buf[], int idx_1, int idx_2) {
    int len = strlen(buf), i;
    char left, right;
    for(i = 0; i < len; i++) {
        left = buf[(idx_1 + i) % len];
        right = buf[(idx_2 + i) % len];
        if(left < right)
            return 1;
        if(left == right)
            continue;
        if(left > right)
            return 0;
    }
    return 1;
}


int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    int t, len, min_idx;
    char buf[maxn + 1];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", buf);
        len = strlen(buf);
        min_idx = 0;
        for(int i = 1; i < len; i++) {
            if(is_smaller_than(buf, i, min_idx))
                min_idx = i;
        }
        for(int i = 0; i < len; i++) {
            printf("%c", buf[(min_idx + i) % len]);
        }
        printf("\n");
    }
    return 0;
}