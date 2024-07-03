#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll INF = 1e15;
void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<ll> sum(n + 1);
    vector<ll> f(p);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum[i + 1] = (sum[i] + x) % p;
    }
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
        dp[0][i] = -INF;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < p; j++) f[j] = -INF;
        if (i == 1) f[0] = 0;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -INF;
            for (int m = 0; m < p; m++) {
                dp[i][j] = max(dp[i][j], f[m] + (sum[j] - m + p) % p);
            }
            f[sum[j]] = max(f[sum[j]], dp[i - 1][j]);
        }
    }
    cout << dp[k][n] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}