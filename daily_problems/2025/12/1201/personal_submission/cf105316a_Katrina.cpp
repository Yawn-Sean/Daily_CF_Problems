#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << endl;


const int MOD = 1e9 + 7;
void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1), dp(n + 1), pre(n + 1), dp2(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    ll sum = pre[n];
    dp[0] = 1, dp2[0] = 1;
    int l = 1;
    for (int r = 1; r <= n; ++r) {
        while (2 * (pre[r] - pre[l - 1]) >= sum) l++;
        
        if (l <= r) {
            int tmp = (l - 2 >= 0) ? dp2[l - 2] : 0;
            dp[r] = (dp2[r - 1] - tmp + MOD) % MOD;
        }
        else dp[r] = 0;

        dp2[r] = (dp2[r - 1] + dp[r]) % MOD;
    }
    cout << dp[n] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
