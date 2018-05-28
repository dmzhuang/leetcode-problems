#include <stdio.h>
#include <string.h>

#define local
const int maxn = 1000;

int main(int argc, char const *argv[])
{
    /* code */
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif

    int kase = 0, n, count_a, count_b, i, tot;
    int answer[maxn+1], guess[maxn+1], a_[10], g_[10];

    while(scanf("%d", &n) == 1 && n > 0) {
        printf("Game %d:\n", ++kase);
        for(i = 0; i < n; i++)
            scanf("%d", &answer[i]);
        while(1) {
            for(i = 0; i < n; i++)
                scanf("%d", &guess[i]);
            if(guess[0] == 0)
                break;
            // for(i = 0; i < n; i++)
            //     printf("%d ", guess[i]);
            // printf("\n");
            count_a = 0;
            for(i = 0; i < n; i++)
                if(answer[i] == guess[i])
                    count_a++;
            memset(a_, 0, sizeof(a_));
            memset(g_, 0, sizeof(g_));
            for(i = 0; i < n; i++) {
                a_[answer[i]]++;
                g_[guess[i]]++;
            }
            tot = 0;
            for(i = 1; i <=  9; i++) {
                tot += (a_[i] > g_[i]) ? g_[i] : a_[i];
            }
            count_b = tot - count_a;
            printf("    (%d,%d)\n", count_a, count_b);
        }
    }

    return 0;
}