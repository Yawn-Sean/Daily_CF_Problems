#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n, x, y, c;
    cin >> n >> x >> y >> c;

    i64 l = 0, r = n * 2ll;
    while (l < r) {
        i64 mid = (l + r) / 2;
        // 没有遮挡
        i64 res = mid * mid * 2 + mid * 2 + 1ll;

        // 边上多出来的
        if (mid > x - 1) {
            res -= (mid - (x - 1)) * (mid - (x - 1));
        }
        if (mid > n - x) {
            res -= (mid - (n - x)) * (mid - (n - x));
        }
        if (mid > y - 1) {
            res -= (mid - (y - 1)) * (mid - (y - 1));
        }
        if (mid > n - y) {
            res -= (mid - (n - y)) * (mid - (n - y));
        }

        // 两边的角多剪掉的
        // 多出来的是一个等腰直角三角形 t - [(x - 1) + (y - 1)]
        if (mid > (x - 1) + (y - 1)) {
            res += (mid - ((x - 1) + (y - 1)) - 1) * 
                   (mid - ((x - 1) + (y - 1))) / 2;
        }
        if (mid > (x - 1) + (n - y)) {
            res += (mid - ((x - 1) + (n - y)) - 1) * 
                   (mid - ((x - 1) + (n - y))) / 2;
        }
        if (mid > (n - x) + (y - 1)) {
            res += (mid - ((n - x) + (y - 1)) - 1) * 
                   (mid - ((n - x) + (y - 1))) / 2;
        }
        if (mid > (n - x) + (n - y)) {
            res += (mid - ((n - x) + (n - y)) - 1) * 
                   (mid - ((n - x) + (n - y))) / 2;
        }

        if (res < c) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l;
    return 0;
}
