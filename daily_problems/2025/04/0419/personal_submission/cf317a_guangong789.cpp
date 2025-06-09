#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 * 32 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;
#define int long long

void solve() {
    int x, y, m;
    cin >> x >> y >> m;
    if (x <= 0 && y <= 0 && m > max(x, y)) {
        cout << -1;
    } else if (m <= max(x, y)) {
        cout << 0;
    } else {
        int ans = 0;
        if (x > y) {
            swap(x, y);
        }
        int tmp = (-x + y -1) / y;
        x += tmp * y;
        ans = tmp;
        while (max(x, y) < m) {
            if (x > y) {
                swap(x, y);
            }
            x += y;
            ans++;
        }
        cout << ans;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}