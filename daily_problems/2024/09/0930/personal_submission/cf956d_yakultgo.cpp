#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') {
                pos[i].push_back(j);
            }
        }
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, 1e9));
    for (int i = 0; i < n; i++) {
        int len = pos[i].size();
        if (len == 0) {
            dp[i][0] = 0;
            continue;
        } else {
            dp[i][0] = pos[i].back() - pos[i].front() + 1;
        }
        for (int left = 0; left <= len; left++) {
            for (int right = 0; right + left <= len; right++) {
                if (left + right == len) {
                    dp[i][left + right] = 0;
                    continue;
                }
                dp[i][left + right] = min(dp[i][left + right], pos[i][len - right - 1] - pos[i][left] + 1);
            }
        }
    }
    vector<vector<int>> f(n + 1, vector<int>(k + 1, 1e9));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int len = pos[i - 1].size();
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= min(j, len); l++) {
                f[i][j] = min(f[i][j], f[i - 1][j - l] + dp[i - 1][l]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= k; i++) ans = min(ans, f[n][i]);
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