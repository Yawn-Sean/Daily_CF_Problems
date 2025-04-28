#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    unordered_map<int, int> dp;
    int ans = 1;
    for (int i : v) {
        int pre = i-1;
        if (dp.contains(pre)) {
            dp[i] = dp[pre] + 1;
        } else {
            dp[i] = 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << n - ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}