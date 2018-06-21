// 栈与递归

// 思考：
// 用机械的转换方法实现：
// 阶乘函数
// 2阶斐波那契数列
// Hanoi塔算法

#include <iostream>
#include <stack>
#include <cassert>
#include <ctime>
using namespace std;

// 1.递归的计算fn
void fu_rec(int n, int& f) {
    int u1, u2;
    if(n < 2)
        f = n + 1;
    else {
        fu_rec(n/2, u1);
        fu_rec(n/4, u2);
        f = u1 * u2;
    }
}

typedef struct ELEM{
    int rd;
    int n;
    int f;
    int u1;
    int u2;
    ELEM(): rd(0), n(n), f(0), u1(0), u2(0) {}
}ELEM;

// 2.非递归计算fn（使用goto）
void fu_nonrec(int n, int& f) {
    stack<ELEM> s;
    ELEM temp, ele;
    temp.rd = 3, temp.n = n;
    s.push(temp); // 压在栈底作“监视哨”

    while(!s.empty()) {
        // 递归入口
        label0: if((s.top()).n < 2) {
            ele = s.top();
            ele.f = ele.n + 1;
            s.pop(); s.push(ele);
            goto label3;
        }
        // 第一处递归
        temp = s.top();
        ele.rd = 1, ele.n = temp.n / 2;
        s.push(ele);
        goto label0;
        label1: temp = s.top(); s.pop();
        ele = s.top();
        ele.u1 = temp.f;
        s.pop(); s.push(ele);
        // 第二处递归
        temp = s.top();
        ele.rd = 2, ele.n = temp.n / 4;
        s.push(ele);
        goto label0;
        label2: temp = s.top(); s.pop();
        ele = s.top();
        ele.u2 = temp.f;
        ele.f = ele.u1 * ele.u2;
        s.pop(); s.push(ele);
        // 结束
        label3: switch((s.top()).rd) {
            case 0: goto label0;
            case 1: goto label1;
            case 2: goto label2;
            case 3: f = (s.top()).f; s.pop(); break;
        }
    }
}

// 3.在2上进一步优化：
// 去掉冗余进栈、出栈
// 消去goto语句
void fu_nonrec_nogoto(int n, int& f) {
    stack<ELEM> s;
    ELEM temp, elem;
    elem.rd = 3; elem.n = n; s.push(elem);

    do {
        // 加入当前节点的所有左节点
        while((temp = s.top()).n >= 2) {
            elem.rd = 1; elem.n = temp.n / 2; s.push(elem);
        }
        // 到达最左节点，计算f
        temp.f = temp.n + 1; s.pop(); s.push(temp);
        // 如果是从第二个递归返回，则上升
        while((temp = s.top()).rd == 2) {
            temp = s.top(); s.pop();
            elem = s.top(); s.pop();
            elem.f = temp.f * elem.u1; s.push(elem);
        }
        if((temp = s.top()).rd == 1) {
            temp = s.top(); s.pop();
            elem = s.top(); s.pop();
            elem.u1 = temp.f; s.push(elem);
            temp.rd = 2; temp.n = temp.n / 4; s.push(temp); // 加入第二个递归
        }
    }while(s.top().rd != 3);
    elem = s.top(); s.pop();
    f = elem.f;
}

int main(int argc, char const *argv[])
{
    const int maxn = 1000;
    int i, f;
    double start, end;

    start = clock();
    for(i = 0; i <= maxn; i++)
        fu_nonrec(i, f);
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for(i = 0; i <= maxn; i++)
        fu_nonrec_nogoto(i, f);
    end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
