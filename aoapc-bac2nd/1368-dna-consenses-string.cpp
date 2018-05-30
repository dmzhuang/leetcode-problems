#include <stdio.h>
#include <string.h>

#define local
#define debug


const int maxm = 50;
const int maxn = 1000;
char str[maxm][maxn+1];


int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    int t = 0;
    scanf("%d", &t);
    while(t--) {
        int m, n;
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++) {
            scanf("%s", str[i]);
        }
        char ans[maxn+1] = {'\0'};
        int error = 0;
        int count[4];
        const char _map[4] = {'A', 'C', 'G', 'T'};
        for(int j = 0; j < n; j++) {
            memset(count, 0, sizeof(count));
            for(int i = 0; i < m; i++) {
                switch(str[i][j]) {
                    case 'A': count[0] += 1; break;
                    case 'C': count[1] += 1; break;
                    case 'G': count[2] += 1; break;
                    case 'T': count[3] += 1; break;
                }
            }
            // printf("pass 1\n");
            int max_count = 0;
            char most_char;
            for(int k = 0; k < 4; k++) {
                if(count[k] > max_count) {
                    max_count = count[k];
                    most_char = _map[k];
                }
            }
            ans[j] = most_char;
            error += (m - max_count);
            // printf("pass 2\n");
        }
        printf("%s\n%d\n", ans, error);
    }
    return 0;
}