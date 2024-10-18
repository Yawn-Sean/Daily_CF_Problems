#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int d, m;
    cin >> d >> m;
    int h = 31 - __builtin_clz(d);
    vector<ll> dp(h+1);
    ll ans = dp[0] = 1 % m;
    for (int i = 1; i < h; ++i) (ans += (ans + 1 << i) % m) %= m;
    if (h) (ans += (d - (1 << h) + 1) * (ans + 1)) %= m;
    cout << ans << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
