#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;
#define int long long

void solve() {
    int n;
    cin >> n;
    n %= 360;
    if (n < 0) {
        n += 360;
    }
    // 偏移在45度及以内就是最佳状态了
    if (n >= 315 || n <= 45) {
        cout << 0;
        return;
    }
    int ans = 0;
    while (true) {
        n -= 90;
        ans++;
        if (n <= 45) {
            break;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
