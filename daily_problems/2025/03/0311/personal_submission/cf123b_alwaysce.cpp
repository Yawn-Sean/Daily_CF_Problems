#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
        观察（x1,y1) - (x2, y2)之间的直线有多少条
        取二者最大值而不是sum
        因为可以走过两个方向的直线的交点
    */

    int a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    auto f = [&](int x, int y) {
        int div = x / y;
        if (y * div > x) { --div; }
        return div;
    };

    int r1 = abs(f(x1 + y1, 2 * a) - f(x2 + y2, 2 * a));
    int r2 = abs(f(x1 - y1, 2 * b) - f(x2 - y2, 2 * b));
    cout << max(r1, r2) << endl;
    return 0;
}
