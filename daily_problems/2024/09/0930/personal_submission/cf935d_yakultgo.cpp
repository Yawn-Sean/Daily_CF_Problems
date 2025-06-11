#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<vector<Z>> dp(n + 1, vector<Z>(2));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (b[i] != 0) {
                if (a[i] > b[i]) {
                    dp[i + 1][1] = dp[i][0] + dp[i][1];
                } else if (a[i] == b[i]) {
                    dp[i + 1][0] = dp[i][0];
                    dp[i + 1][1] = dp[i][1];
                } else {
                    dp[i + 1][1] = dp[i][1];
                }
            } else {
                dp[i + 1][1] = dp[i][1] + dp[i][0] * (a[i] - 1) / m;
                dp[i + 1][0] = dp[i][0] / m;
            }
        } else {
            if (b[i] != 0) {
                dp[i + 1][1] = dp[i][1] + dp[i][0] * (m - b[i]) / m;
                dp[i + 1][0] = dp[i][0] / m;
            } else {
                dp[i + 1][1] = dp[i][1] + dp[i][0] * (m - 1) / (2 * m);
                dp[i + 1][0] = dp[i][0] / m;
            }
        }
    }
    cout << dp[n][1] << endl;
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