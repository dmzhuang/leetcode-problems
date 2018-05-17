#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Point {
    int x, y;
    Point(int x=0, int y=0) :x(x), y(y) {}
};

Point operator+ (const Point& a, const Point& b) {
    return Point(a.x + b.x, a.y + b.y);
}

ostream& operator<< (ostream& out, const Point& a) {
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

template<typename T>
T sum(T* begin, T* end) {
    T ans = 0;
    for(T *p=begin; p != end; p++) {
        ans = ans + *p;         // Point只定义了'+'，没有定义'+='
    }
    return ans;
}

template<typename T>
struct TPoint {
    T x, y;
    TPoint(T x, T y) :x(x), y(y) {}
};

template<typename T>
TPoint<T> operator+ (const TPoint<T>& a, const TPoint<T>& b) {
    return TPoint<T>(a.x + b.x, a.y + b.y);
}

template<typename T>
ostream& operator<< (ostream& out, const TPoint<T>& a) {
    out << "(" << a.x << "," << a.y << ")";
    return out;
}

int main() {
    string line;
    while(getline(cin, line)) {
        int sum = 0, x;
        stringstream ss(line);
        while(ss >> x) sum +=x;
        cout << sum << endl;
    }

    Point a, b(1, 2);
    a.x = 3;
    cout << a + b << endl;

    double d_arr[] = {1.1, 2.2, 3.3};
    cout << sum(d_arr, d_arr+3) << endl;

    Point p_arr[] = {Point(1,1), Point(2,2), Point(3,3)};
    cout << sum(p_arr, p_arr+3) << endl;

    TPoint<int> tpi_a(1,1), tpi_b(2,2);
    cout << tpi_a + tpi_b << endl;

    TPoint<double> tpd_a(1.1,1.1), tpd_b(2.2, 2.2);
    cout << tpd_a + tpd_b << endl;

    return 0;
}
