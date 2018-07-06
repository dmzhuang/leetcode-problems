#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int* findNext(const string& P);
int KMPStrMatching(const string& T, const string& P, int* N, int start);
int KMP(const string& T, const  string& P);


int main(int argc, char const *argv[])
{
    string target, pattern;
    target = "helloworld";
    pattern = "wor";

    cout << KMP(target, pattern) << endl;

    return 0;
}

int* findNext(const string& P) {
    int j, k;
    int m = P.length();
    int *next = new int[m];
    next[0] = -1;
    j = 0; k = -1;
    while(j < m - 1) {
        while(k >= 0 && P[k] != P[j])   // 不等则采用KMP自找首尾子串
            k = next[k];                // k递归地往前找
        j++; k++;
        next[j] = k;
    }
    return next;
}

int KMPStrMatching(const string& T, const string& P, int* N, int start) {
    int j = 0;      // 模式的下标变量
    int i = start;  // 目标的下标变量
    int pLen = P.length();
    int tLen = T.length();
    if(tLen - start < pLen) return -1;

    while(j < pLen && i < tLen) {
        if(j == -1 || T[i] == P[j])
            i++, j++;
        else j = N[j];
    }
    if(j >= pLen)
        return (i - pLen);
    else return -1;
}

int KMP(const string& T, const  string& P) {
    int *next = findNext(P);
    return KMPStrMatching(T, P, next, 0);
}
