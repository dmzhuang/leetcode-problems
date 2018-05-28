#include <stdio.h>
#include <string.h>

#define local
const int maxn = 100000;
int generator[maxn + 1];

int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    int t, n, i, sum, temp;
    memset(generator, 0, sizeof(generator));
    for(i = maxn; i >= 0; i--) {
        temp = i; sum = temp;
        while(temp) {
            sum += (temp % 10);
            temp /= 10;
        }
        if(sum <= maxn)
            generator[sum] = i;
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", generator[n]);
    }

    return 0;
}