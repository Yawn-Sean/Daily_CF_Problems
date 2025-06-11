#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int y1, y2, y, x0, y0, r;
    cin >> y1 >> y2 >> y >> x0 >> y0 >> r;
    long double b = 2 * (y - r) - (y1 + r);
    long double k = (y0 - b) / x0;
    long double x = (y - r - b) / k;
    if (1LL * (y - r - y2) * (y - r - y2) + x * x > 1LL * r * r + 1e-9) {
        auto _k = -k, _b = k * x + y - r;
        if ((_b - y2) * (_b - y2) / (_k * _k + 1) > 1LL * r * r + 1e-9) println("{:.14f}", x);
        else println("-1");
    } else println("-1");
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
