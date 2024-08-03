#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    ll n, mod;
    cin >> n >> mod;
    vector<ll> dp(n+5);
    ll sum = 0;
    dp[n] = 1;
    for(int i=n; i>=1; i--) {
        dp[i] += sum;
        dp[i] %= mod;
        for(int j=2; j<=i; j=(i/(i/j)+1)) {
            dp[i/j] += ((i/(i/j))-j+1) * dp[i] % mod;
            dp[i/j] %= mod;
        }
        sum = (sum + dp[i]) % mod;
    }
    cout << dp[1] % mod;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
