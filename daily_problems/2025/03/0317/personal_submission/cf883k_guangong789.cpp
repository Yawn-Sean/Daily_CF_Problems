#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> s(n+1), g(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> g[i];
        g[i] += s[i];
    }
    for (int i = 2; i <= n; ++i) {
        g[i] = min(g[i], g[i-1]+1);
    }
    for (int i = n-1; i >= 1; --i) {
        g[i] = min(g[i], g[i+1]+1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i] < s[i]) {
            ans = -1;
            break;
        } else {
            ans += g[i] - s[i];
        }
    }
    if (ans == -1) {
        cout << ans;
    } else {
        cout << ans << endl;
        for (int i = 1; i <= n; ++i) {
            cout << g[i] << ' ';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}