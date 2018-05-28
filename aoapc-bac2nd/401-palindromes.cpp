#include <cstdio>
#include <cstring>
#include <cctype>

#define local

#define FLAG_PALIN (0X0)
#define FLAG_MIRRO (0X1)

char mirror[] = "1SE$Z$$8$A$$$3$$HIL$JM$O$$$2TUVWXY5";

const char* msg[] = {
    "not a palindrome",
    "a regular palindrome",
    "a mirrored string",
    "a mirrored palindrome"
};


// int judge(char str[], int n) {
//     int ret_val = 0, i;
//     // judge if str is palindrome
//     for(i = 0; i < n / 2; i++)
//         if(str[i] != str[n-1-i]) {
//             break;
//         }
//     if(i >= n/2)
//         ret_val |=(1 << FLAG_PALIN);
//     // judge if str is mirrored
//     for(i = 0; i < (n+1) / 2; i++) {
//         char ch = str[i], reverse;
//         if(isalpha(ch)) {
//             reverse = mirror[ch-'A'+9];
//         }else { // else ch should be a digit
//             reverse = mirror[ch-'1'];
//         }
//         if(reverse != str[n-1-i])
//             break;
//     }
//     if(i >= n/2)
//         ret_val |=(1 << FLAG_MIRRO);

//     return ret_val;
// }


// void printResult(char* str, int status) {
//     printf("%s -- ", str);
//     if(!((status >> FLAG_PALIN) & 0x1) && !((status >> FLAG_MIRRO) & 0x1)) {
//         printf("is not a palindrome.\n\n");
//     }else if(((status >> FLAG_PALIN) & 0x1) && !((status >> FLAG_MIRRO) & 0x1)) {
//         printf("is a regular palindrome.\n\n");
//     }else if(!((status >> FLAG_PALIN) & 0x1) && ((status >> FLAG_MIRRO) & 0x1)) {
//         printf("is a mirrored string.\n\n");
//     }else {
//         printf("is a mirrored palindrome.\n\n");
//     }
//     return;
// }


int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif

    char str[30] = {'\0'};
    int len, p, m;
    while(scanf("%s", str) == 1) {
        len = strlen(str);
        p = 1, m = 1;
        for(int i = 0; i < len / 2; i++)
            if(str[i] != str[len-1-i]) {
                p = 0; break;
            }
        char r;
        for(int i = 0; i < (len + 1) / 2; i++) {
            if(isalpha(str[i])) r = mirror[str[i] - 'A' + 9];
            else r = mirror[str[i] - '1'];
            if(r != str[len-1-i]) {
                m = 0; break;
            }
        }
        printf("%s -- is %s.\n\n", str, msg[m * 2 + p]);
    }
    return 0;
}