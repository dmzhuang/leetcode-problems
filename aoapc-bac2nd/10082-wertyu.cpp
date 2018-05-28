#include <cstdio>
#include <cctype>

#define local

char plain[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
// const char crypt[] = "";

int main(int argc, char const *argv[])
{
    #ifdef local
    freopen("data.in", "rb", stdin);
    #endif

    int c, pos, isOk;
    while((c = getchar()) != EOF) {
        isOk = 0;
        if(isalpha(c))
            c = tolower(c);
        for(pos = 0; pos < sizeof(plain)/sizeof(char); pos++) {
            if(plain[pos] == c) {
                isOk = 1;
                break;
            }
        }

        if(isOk)
            printf("%c", isalpha(plain[pos-1]) ? toupper(plain[pos-1]) : plain[pos-1]);
        else printf("%c", c);
    }

    return 0;
}