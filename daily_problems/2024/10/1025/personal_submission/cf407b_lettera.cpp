#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
const int mod = 1e9 + 7;
ll MOD(ll x)
{
    return (x % mod + mod) % mod;
}
void solve()
{
    ll ans = 0;
    int n;
    cin >> n;
    vector<ll> a(n + 1), dp(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // dp[i]:1->i
    for (int i = 2; i <= n + 1; i++)
    {
        // 先到i-1,再到p[i-1],再到i-1,再到i
        dp[i] = MOD(dp[i - 1] + dp[i - 1] - dp[a[i - 1]] + 2);
    }
    cout << dp[n + 1];
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
