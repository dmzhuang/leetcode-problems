// 栈与递归之阶乘函数

#include <iostream>
#include <stack>
#include <cassert>
#include <ctime>
using namespace std;

const int maxn = 12;

// 1、阶乘公式的递归形式
int factorial_rec(int n, int& f) {
    int u1;
    if(n <= 0) {
        f = 1;
    }
    else {
        factorial_rec(n-1, u1);
        f = u1 * n;
    }
    return f;
}

typedef struct ELEM {
    int rd;
    int n;
    int f;
}ELEM;

// 2、非递归计算阶乘（使用goto)
int factorial_nonrec(int n, int& f) {
    stack<ELEM> s;
    ELEM temp, elem;
    elem.rd = 2; elem.n = n;
    s.push(elem);

    while(!s.empty()) {
        label0: if((elem = s.top()).n <= 0) {
            elem.f = 1; s.pop(); s.push(elem);
            goto label2;
        }
        temp.rd = 1; temp.n = elem.n-1; s.push(temp);
        goto label0;
        label1: temp = s.top(); s.pop();
        elem = s.top(); elem.f = elem.n * temp.f; s.pop(); s.push(elem);
        label2: switch(s.top().rd) {
            case 0: goto label0; break;
            case 1: goto label1; break;
            case 2: f = s.top().f; s.pop(); break;
        }
    }
    return f;
}

// 3、非递归计算阶乘(不使用goto)
int factorial_nonrec_nogoto(int n, int& f) {
    stack<ELEM> s;
    ELEM temp, elem;
    elem.rd = 2, elem.n = n; s.push(elem);

    do{
        while((elem = s.top()).n > 0) {
            temp.rd = 1; temp.n = elem.n-1; s.push(temp);
        }
        elem.f = 1; s.pop(); s.push(elem);
        while(s.top().rd == 1) {
            temp = s.top(); s.pop();
            elem = s.top(); elem.f = elem.n * temp.f; s.pop(); s.push(elem);
        }
    }while(s.top().rd != 2);
    return f = s.top().f;
}


int main(int argc, char const *argv[])
{
    int i, f1, f2, f3;
    double start, end;

    for(i = 0; i <= maxn; i++) {
        factorial_rec(i, f1);
        factorial_nonrec(i, f2);
        factorial_nonrec_nogoto(i, f3);
        assert(f1 == f2);
        assert(f1 == f3);
    }

    return 0;
}
