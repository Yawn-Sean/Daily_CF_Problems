#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    // diff1表示i在上面，j下面两个连续的差值
    vector<vector<int>> diff1(n, vector<int>(n, 1e9));
    // diff2表示i在第一行，j在最后一行
    vector<vector<int>> diff2(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                diff1[i][j] = min(diff1[i][j], abs(a[j][k] - a[i][k]));
            }
            for (int k = 0; k + 1 < m; k++) {
                diff2[i][j] = min(diff2[i][j], abs(a[i][k + 1] - a[j][k]));
            }
        }
    }
    int ans = 0;
    // dp[i][j]表示状态为i，最后一个为j的最大值
    // 枚举一下起点
    for (int i = 0; i < n; i++) {
        vector<vector<int>> dp(1 << n, vector<int>(n));
        dp[1 << i][i] = 1e9;
        for (int sta = 0; sta < (1 << n); sta++) {
            for (int k = 0; k < n; k++) {
                if ((sta & (1 << k)) == 0) continue;
                for (int nex = 0; nex < n; nex++) {
                    if (sta & (1 << nex)) continue;
                    dp[sta | (1 << nex)][nex] = max(dp[sta | (1 << nex)][nex], min(dp[sta][k], diff1[k][nex]));
                }
            }
        }
        // 枚举一下终点
        for (int last = 0; last < n; last++) {
            ans = max(ans, min(dp[(1 << n) - 1][last], diff2[i][last]));
        }
    }
    cout << ans << endl;
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