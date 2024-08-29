#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int x, y;
    int mx = 123, my = 123, Mx = -123, My = -123;
    int ma = 123, ms = 123, Ma = -123, Ms = -123;
    for (int i = 0; i < 4; ++i) {
        cin >> x >> y;
        mx = min(x, mx); Mx = max(x, Mx);
        my = min(y, my); My = max(y, My);
    }
    for (int i = 0; i < 4; ++i) {
        cin >> x >> y;
        ma = min(x + y, ma); Ma = max(x + y, Ma);
        ms = min(x - y, ms); Ms = max(x - y, Ms);
    }
    bool suc = false;
    for (x = mx; x <= Mx && !suc; ++x) for (y = my; y <= My && !suc; ++y) if (x + y >= ma && x + y <= Ma && x - y >= ms && x - y <= Ms) suc = true;
    cout << (suc ? "YES\n" : "NO\n");
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
