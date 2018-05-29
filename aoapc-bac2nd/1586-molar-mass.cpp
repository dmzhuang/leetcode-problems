#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define local
const int max_len = 80;


int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif
    /* code */
    int t, len;
    double ans;
    char buf[max_len + 1];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", buf);
        len = strlen(buf);
        ans = 0;
        double element = 0.00;
        int count = 0;
        for(int i = 0; i < len; i++) {
            if(isalpha(buf[i])) {
                ans += element * count;
                switch(buf[i]) {
                    case 'C': element = 12.01; break;
                    case 'H': element = 1.008; break;
                    case 'O': element = 16.00; break;
                    case 'N': element = 14.01; break;
                    default: element = 0.00; break;
                }
                count = 1;
            }
            else if(isdigit(buf[i])) {
                if(count == 1 && !isdigit(buf[i-1]))
                    count = buf[i] - '0';
                else
                    count = count * 10 + (buf[i] - '0');
            }
        }
        ans += element * count;
        printf("%.3f\n", ans);
    }

    return 0;
}