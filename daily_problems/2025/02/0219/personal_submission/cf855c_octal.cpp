#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;

ll qmi(ll a, ll b, ll mod)
{
	ll res = 1;
	while(b) {
		if(b & 1) res = res*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}
inline void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+5);
    for(int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll k, x;
    cin >> k >> x;
    vector<vector<ll>> dp0(x+1, vector<ll>(n+1));
    auto dp1 = dp0;
    auto dp2 = dp0;
    // sta=0: any, sta=1: less than k, sta=2: not k
    function<void(int, int)> dfs = [&](int u, int fa) {
        vector<int> s0(x+1), s1(x+1), s2(x+1);
        s0[0] = s1[0] = s2[0] = 1;
        for(int v: g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            for(int i=x; i>=0; i--) {
                ll t0 = 0, t1 = 0, t2 = 0;
                for(int j=0; j<=i; j++) {
                    (t0 += s0[i-j] * (dp0[j][v] + dp1[j][v] + dp2[j][v]) % mod) %= mod;
                    (t1 += s1[i-j] * dp0[j][v] % mod) %= mod;
                    (t2 += s2[i-j] * (dp0[j][v] + dp2[j][v]) % mod) %= mod;
                }
                s0[i] = t0, s1[i] = t1, s2[i] = t2;
            }
        }
        for(int i=0; i<=x; i++) {
            dp0[i][u] = s0[i] * (k-1) % mod;
            dp2[i][u] = s2[i] * (m-k) % mod;
        }
        for(int i=1; i<=x; i++) {
            dp1[i][u] = s1[i-1];
        }
    };
    dfs(1, 0);
    ll res = 0;
    for(int i=0; i<=x; i++) {
        res += dp0[i][1] + dp1[i][1] + dp2[i][1];
        res %= mod;
    }
    cout << res << endl;
}
