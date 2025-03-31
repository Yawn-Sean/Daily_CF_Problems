#include <bits/stdc++.h>
 
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y, c;
    cin >> n >> x >> y >> c;
    auto f = [&] (int64 t) -> int64 {
        // 1 + 3 + .. + (2 * t + 1) = (t + 1) ^ 2
        // 1 + 3 + .. + (2 * (t - 1) + 1) = t ^ 2
        int64 res = 1LL * (t + 1) * (t + 1) + 1LL * t * t;
        if (t + 1 > x) {
            // 1 + 3 + .. + ((t - x) * 2 + 1)
            int64 top = 1LL * (t - x + 1) * (t - x + 1);
            res -= top;
        }
        if (t > n - x) {
            // 1 + 3 + .. + ((t - (n - x) - 1) * 2 + 1)
            int64 bottom = 1LL * (t - (n - x)) * (t - (n - x));
            res -= bottom;
        }
        if (t + 1 > y) {
            // 1 + 3 + .. + ((t - y) * 2 + 1)
            int64 left = 1LL * (t - y + 1) * (t - y + 1);
            res -= left;
        }
        if (t > n - y) {
            // 1 + 3 + .. + ((t - (n - y) - 1) * 2 + 1)
            int64 right = 1LL * (t - (n - y)) * (t - (n - y));
            res -= right;
        }
        if (t + 1 > x && t + 1 > y) {
            // ((t - x) * 2 + 1) - ((y - 1) * 2 + 1) > 0
            int64 tl = (((t - x) * 2 + 1) - ((y - 1) * 2 + 1)) / 2;
            if (tl > 0) {
                res += 1LL * (1 + tl) * tl / 2;
            }
        }
        if (t + 1 > x && t > n - y) {
            // ((t - x) * 2 + 1) - ((n - y) * 2 + 1) > 0
            int64 tr = (((t - x) * 2 + 1) - ((n - y) * 2 + 1)) / 2;
            if (tr > 0) {
                res += 1LL * (1 + tr) * tr / 2;
            }
        }
        if (t > n - x && t + 1 > y) {
            // ((t - (n - x) - 1) * 2 + 1) - ((y - 1) * 2 + 1) > 0
            int64 bl = (((t - (n - x) - 1) * 2 + 1) - ((y - 1) * 2 + 1)) / 2;
            if (bl > 0) {
                res += 1LL * (1 + bl) * bl / 2;
            }
        }
        if (t > n - x && t > n - y) {
            // ((t - (n - x) - 1) * 2 + 1) - ((n - y) * 2 + 1) > 0
            int64 br = (((t - (n - x) - 1) * 2 + 1) - ((n - y) * 2 + 1)) / 2;
            if (br > 0) {
                res += 1LL * (1 + br) * br / 2;
            }
        }
        return res;
    };
    int64 lo = 0, hi = 1e9;
    while (lo <= hi) {
        int64 mid = (hi - lo) / 2 + lo;
        if (f(mid) >= c) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
    return 0;
}

