#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int64 exgcd(int64 a, int64 b, int64& x, int64& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64 x1, y1;
    int64 d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, b, k;
        cin >> r >> b >> k;
        if (r == b) {
            cout << "OBEY" << "\n";
        } else {
            int d = gcd(r, b);
            r /= d;
            b /= d;
            if (r > b) swap(r, b);
            if (r == 1) {
                if (b > k) {
                    cout << "REBEL" << "\n";
                } else {
                    cout << "OBEY" << "\n";
                }
            } else {
                int64 x, y;
                d = exgcd(b, r, x, y);
                int64 n = x;
                int64 cnt = n * b / r - (n - 1) * b / r;
                if (cnt >= k) {
                    cout << "REBEL" << "\n";
                } else {
                    cout << "OBEY" << "\n";
                }
            }
        }
    }
    return 0;
}
