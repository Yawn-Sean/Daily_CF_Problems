#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;
    long long g = gcd(a, b);
    a /= g;
    b /= g;
    long long k = min(n / a, m / b);
    long long len = a * k, wid = b * k;
    long long xl = max(0LL, x - len), xr = min(x, n - len);
    long long Tx = 2 * x - len;
    long long fx = (Tx >= 0 ? Tx / 2 : Tx / 2 - (Tx % 2 != 0));
    long long best_x1 = xl, best_dx = LLONG_MAX;
    for (long long c : {fx, fx + 1, xl, xr}) {
        if (c < xl || c > xr) continue;
        long long dx = llabs(2 * c - Tx);
        if (dx < best_dx || (dx == best_dx && c < best_x1)) {
            best_dx = dx;
            best_x1 = c;
        }
    }
    long long x1 = best_x1, x2 = x1 + len;
    long long yl = max(0LL, y - wid), yr = min(y, m - wid);
    long long Ty = 2 * y - wid;
    long long fy = (Ty >= 0 ? Ty / 2 : Ty / 2 - (Ty % 2 != 0));
    long long best_y1 = yl, best_dy = LLONG_MAX;
    for (long long c : {fy, fy + 1, yl, yr}) {
        if (c < yl || c > yr) continue;
        long long dy = llabs(2 * c - Ty);
        if (dy < best_dy || (dy == best_dy && c < best_y1)) {
            best_dy = dy;
            best_y1 = c;
        }
    }
    long long y1 = best_y1, y2 = y1 + wid;
    cout << x1 << " " << y1 << " " << x2 << " " << y2;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}