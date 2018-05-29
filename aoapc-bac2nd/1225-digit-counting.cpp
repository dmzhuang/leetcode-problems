#include <stdio.h>
#include <string.h>

#define local
const int max_n = 10000;

int ans[max_n + 1][10];


int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    int i, j, temp;
    memset(ans, 0, sizeof(ans));
    ans[1][1] = 1;
    for(i = 2; i < max_n; i++) {
        for(j = 0; j < 10; j++)
            ans[i][j] = ans[i-1][j];
        temp = i;
        while(temp) {
            ans[i][temp % 10] += 1;
            temp /= 10;
        }
    }

    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%d", ans[n][0]);
        for(j = 1; j < 10; j++)
            printf(" %d", ans[n][j]);
        printf("\n");
    }

    return 0;
}