#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int powmod(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = x * res % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    vector<int> pre(2, 1);
    for (int i = 2; i <= n; i++) {
        dp[i] = pre[i % 2];
        pre[(i + 1) % 2] += dp[i], pre[(i + 1) % 2] %= mod;
    }
    int ans = dp[n] * powmod(powmod(2, n), mod - 2) % mod;
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
