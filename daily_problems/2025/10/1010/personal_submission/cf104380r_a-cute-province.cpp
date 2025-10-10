#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 5e5+10;
const int mod = 1e9 + 7;
int f[N];
int qpow(int a,int b){
    int res = 1;
    while(b){
        if (b&1)res = res * a % mod;
        b >>= 1;
        a = a * a%mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod-2)%mod;
}
int C(int n, int m){
    if(n < m || m < 0)return 0ll;
    if(n == m || m == 0)return 1ll;
    return f[n] * inv(f[m])%mod  *inv(f[n-m])%mod;
}
void solve() {
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i ++)cin >> a[i];
    int Q = 0;
    for (int i = L-1; i <= R-1; i ++)Q += C(0, i)%mod, Q %=mod;
    int ans = Q * a[n]%mod * qpow(2, n-1)%mod;
    for(int i = n-1; i >= 1; i --){
        Q = 2 * Q - C(n-i-1, R-1) + C(n-i-1, L-2);
        Q = (Q%mod + mod)%mod;
        ans += a[i] * Q %mod * qpow(2, i-1) %mod;
        ans %= mod;
    }
    Q = 0;
    for (int i = L-n; i <= R-n; i ++)Q += C(0, i)%mod, Q %=mod;
    ans += Q * a[n]%mod * qpow(2, n-1)%mod;
    ans %= mod;
    for(int i = n-1; i >= 1; i --){
        Q = 2 * Q - C(n-i-1, L-i-1) + C(n-i-1, R-i);
        Q = (Q%mod + mod)%mod;
        ans += a[i] * Q %mod * qpow(2, i-1) %mod;
        ans %= mod;
    }
    cout  << ans << '\n';
}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    f[0] = 1;
    for(int i = 1; i < N; i ++)f[i] = f[i-1] * i %mod;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
