#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int dp[2005][2005];
void solve(){
    dp[0][0] = 1;
    for (int i = 0; i <= 2e3; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
            if (j > 0) dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % mod;
        }
    }
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cur = 0;
    int mi = INT_MAX;
    for (auto c : s) {
        if (c == '(') cur++;
        else cur--;
        mi = min(cur, mi);
    }
    int ans = 0;
    int st = max(0ll, -mi);
    for (int i = 0; i <= n - m; i++) {
        for (int j = st; j <= i; j++) {
            if (cur + j < 0 || cur + j > n - m - i) continue;
            ans = (ans + dp[i][j] * dp[n - m - i][cur + j] % mod) % mod;
        }
    }
    cout << ans << endl;
    
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
