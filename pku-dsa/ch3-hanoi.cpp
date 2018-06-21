// 栈与递归之Hanoi塔算法
// 将n个木块从A经过B移到C

#include <iostream>
#include <stack>
#include <cassert>
#include <ctime>
#include <cstdlib>
using namespace std;


void move(int block, char src, char dst) {
    cout << "move #" << block << " from " << src << " to " << dst << endl;
}

// 1、汉诺塔的递归形式
void hanoi_rec(int n, char src, char dst, char transfer) {
    if(n == 1) {
        move(n, src, dst);
    } else {
        hanoi_rec(n-1, src, transfer, dst);
        move(n, src, dst);
        hanoi_rec(n-1, transfer, dst, src);
    }
}

typedef struct ELEM {
    int rd;
    int n;
    char src;
    char dst;
    char transfer;
} ELEM;

// 2、汉诺塔的非递归形式
void hanoi_nonrec(int n, char src, char dst, char transfer) {
    stack<ELEM> s;
    ELEM temp, elem;
    elem.rd = 3; elem.n = n;
    elem.src = src; elem.dst = dst; elem.transfer = transfer; s.push(elem);

    do{
        while((elem = s.top()).n > 1) {
            temp.rd = 1; temp.n = elem.n - 1;
            temp.src = elem.src; temp.dst = elem.transfer; temp.transfer = elem.dst;
            s.push(temp);
        }
        move(elem.n, elem.src, elem.dst);
        while(s.top().rd == 2) {
            s.pop();
        }
        if(s.top().rd == 1) {
            s.pop();
            elem = s.top();
            move(elem.n, elem.src, elem.dst);
            temp.rd = 2; temp.n = elem.n - 1;
            temp.src = elem.transfer; temp.dst = elem.dst; temp.transfer = elem.src;
            s.push(temp);
        }
    }while(s.top().rd != 3);
}


int main(int argc, char const *argv[])
{
    const int maxn = 20;
    int i, f;
    double start, end;

    hanoi_rec(maxn, 'A', 'C', 'B');
    // hanoi_nonrec(maxn, 'A', 'C', 'B');

    // start = clock();
    // for(i = 1; i <= maxn; i++)
    //     hanoi_rec(i, 'A', 'C', 'B');
    // end = clock();
    // cout << (end - start) / CLOCKS_PER_SEC << endl;

    // start = clock();
    // for(i = 1; i <= maxn; i++)
    //     hanoi_nonrec(i, 'A', 'C', 'B');
    // end = clock();
    // cout << (end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
