#include <iostream>
#include <string>
using namespace std;

// 求数组a中有序子数组中最长的长度
// 若a所有元素按照降序方式排列，则外层循环n-1次，每次内层只执行1次，整个开销为theta(n)
// 若a所有元素按照升序方式排列，则外层循环n-1次，每次内层执行n-1-i次，整个开销为theta(n^2)
// 所以，一般来说，时间复杂度是omega(n)，也是O(n^2)
int LongestAscentLength(int a[], int n) {
    int i, j, length;

    for(i = 0, length = 1; i < n - 1; i++) {
        for(j = i + 1; j < n && a[j - 1] < a[j]; j++)
            if(length < j - i + 1)
                length = j - i + 1;
    }
    return length;
}


int main(int argc, char const *argv[]) {

    int a[] = {1,8,1,2,5,0,11,9,10,11,12};
    cout << LongestAscentLength(a, sizeof(a) / sizeof(int)) << endl;

    return 0;
}
