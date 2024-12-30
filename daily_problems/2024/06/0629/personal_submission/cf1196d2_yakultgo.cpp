#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
/*
    只有RGB、GBR、BRG三种情况
*/
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int dp[3][n + 1];
    for (int i = 0; i < 3; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + (s[i - 1] != "RGB"[i % 3]);
        dp[1][i] = dp[1][i - 1] + (s[i - 1] != "GBR"[i % 3]);
        dp[2][i] = dp[2][i - 1] + (s[i - 1] != "BRG"[i % 3]);
    }
    int ans = 1e9;
    for (int i = 0; i <= n - k; i++) {
        ans = min(ans, dp[0][i + k] - dp[0][i]);
        ans = min(ans, dp[1][i + k] - dp[1][i]);
        ans = min(ans, dp[2][i + k] - dp[2][i]);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}