#include <cstdio>
#include <cstring>


// 蛇形填数
void snakeArray(int n) {
    const int maxn = 8;
    int a[maxn][maxn];
    memset(a, 0, sizeof(a));

    int x, y, tot = 0;
    tot = a[x=0][y=n-1] = 1;
    while(tot < n * n) {
        while(x+1<n && !a[x+1][y]) a[++x][y] = ++tot;
        while(y-1>=0 && !a[x][y-1]) a[x][--y] = ++tot;
        while(x-1>=0 && !a[x-1][y]) a[--x][y] = ++tot;
        while(y+1<n && !a[x][y+1]) a[x][++y] = ++tot;
    }
   
    for(x = 0; x < n; x++) {
        for(y = 0; y < n; y++)
            printf("%3d", a[x][y]);
        printf("\n");                
    }    
    return;
}


// TODO 竖式问题


int main() {

    snakeArray(4);

    return 0;
}
