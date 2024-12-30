#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                dp[i][j] = dp[i][i + len / 2 - 1] + 1;
            }
        }
    }
    vector<ll> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cnt[dp[i][j]]++;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        cnt[i] += cnt[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
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