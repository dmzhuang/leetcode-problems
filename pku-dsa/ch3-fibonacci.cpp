// 栈与递归之2阶斐波那契数列

#include <iostream>
#include <stack>
#include <cassert>
#include <ctime>
using namespace std;

const int maxn = 10;

// 1、斐波那契数列的递归形式
int fibo_rec(int n, int& f) {
    int u1, u2;
    if(n <= 1) {
        f = n;
    }
    else {
        fibo_rec(n-1, u1);
        fibo_rec(n-2, u2);
        f = u1 + u2;
    }
    return f;
}

typedef struct ELEM_FIBO {
    int rd;
    int n;
    int f;
    int u1;
    int u2;
}ELEM_FIBO;

// 2、非递归计算fibo（使用goto)
int fibo_nonrec(int n, int& f) {
    stack<ELEM_FIBO> s;
    ELEM_FIBO temp, elem;
    elem.rd = 3; elem.n = n;
    s.push(elem);

    while(!s.empty()) {
        label0: if((elem = s.top()).n <= 1) {
            elem.f = elem.n; s.pop(); s.push(elem);
            goto label3;
        }
        temp.rd = 1; temp.n = elem.n-1; s.push(temp);
        goto label0;
        label1: temp = s.top(); s.pop();
        elem = s.top(); elem.u1 = temp.f; s.pop(); s.push(elem);
        temp.rd = 2; temp.n = elem.n-2; s.push(temp);
        goto label0;
        label2: temp = s.top(); s.pop();
        elem = s.top(); elem.f = temp.f + elem.u1; s.pop(); s.push(elem);
        label3: switch(s.top().rd) {
            case 0: goto label0; break;
            case 1: goto label1; break;
            case 2: goto label2; break;
            case 3: f = s.top().f; s.pop(); break;
        }
    }
    return f;
}

// 3、非递归计算fibo(不使用goto)
int fibo_nonrec_nogoto(int n, int& f) {
    stack<ELEM_FIBO> s;
    ELEM_FIBO temp, elem;
    elem.rd = 3, elem.n = n; s.push(elem);

    do{
        while((elem = s.top()).n > 1) {
            temp.rd = 1; temp.n = elem.n-1; s.push(temp);
        }
        elem.f = elem.n; s.pop(); s.push(elem);
        while(s.top().rd == 2) {
            temp = s.top(); s.pop();
            elem = s.top(); elem.f = elem.u1 + temp.f; s.pop(); s.push(elem);
        }
        if(s.top().rd == 1) {
            temp = s.top(); s.pop();
            elem = s.top(); elem.u1 = temp.f; s.pop(); s.push(elem);
            temp.rd = 2; temp.n = elem.n-2; s.push(temp);
        }
    }while(s.top().rd != 3);
    return f = s.top().f;
}


int main(int argc, char const *argv[])
{
    int i, f1, f2, f3;
    double start, end;

    for(i = 0; i <= maxn; i++) {
        fibo_rec(i, f1);
        fibo_nonrec(i, f2);
        fibo_nonrec_nogoto(i, f3);
        assert(f1 == f2);
        assert(f1 == f3);
    }

    // start = clock();
    // for(i = 0; i <= maxn; i++) {
    //     fibo_rec(i, f);
    // }
    // end = clock();
    // cout << (end - start) / CLOCKS_PER_SEC << endl;

    // start = clock();
    // for(i = 0; i <= maxn; i++) {
    //     fibo_nonrec(i, f);
    //     cout << f << endl;
    // }
    // end = clock();
    // cout << (end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
