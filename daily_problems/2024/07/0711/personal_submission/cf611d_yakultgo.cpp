#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string num;
    cin >> num;
    int mod = 1e9 + 7;
    if (num[0] == '0') {
        cout << 0 << endl;
    }
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (num[i] == num[j]) {
                lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }
    }
    auto cmp = [&](int l1, int l2, int r2) {
        int len = lcp[l1][l2];
        if (len >= r2 - l2 + 1) return false;
        return num[l1 + len] < num[l2 + len];
    };
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < n; i++) {
        if (num[i] == '0') continue;
        for (int j = i - 1, k = i, sum = 0; k < n; k++, j--) {
            dp[i][k] = sum;
            if (j < 0) continue;
            if (num[j] > '0' && cmp(j, i, k))
                dp[i][k] = (dp[i][k] + dp[j][i - 1]) % mod;
            sum = (sum + dp[j][i - 1]) % mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + dp[i][n - 1]) % mod;
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