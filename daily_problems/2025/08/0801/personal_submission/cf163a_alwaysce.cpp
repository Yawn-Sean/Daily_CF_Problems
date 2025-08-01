#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 mod = 1e9 + 7;
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    // dp[i][j] = dp[i][j+1]
    /// if s[i]==t[j]:
    // dp[i][j] += dp[i+1][j+1] + 1
   vector<vector<i64>> dp(n + 1, vector<i64>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp[i][j] = dp[i][j + 1];
            if (s[i] == t[j]) {
                dp[i][j] = ((dp[i][j] + dp[i + 1][j + 1]) % mod + 1) % mod;
            }    
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[i][0]) % mod; // sum all dp[i][0] values
    }
    cout << ans << "\n";
    return 0;
}
