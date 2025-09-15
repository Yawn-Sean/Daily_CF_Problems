#include <bits/stdc++.h>

#define int long long
#define ld long double
#define ll long long
#define lowbit(x) x & -x

using namespace std;

const int N = 6000;
const int mod = 1e9 + 7;
const int INF = 1e18;

#define endl '\n'
#define rep(l, r) for (int i = l; i <= r; i++)
#define lep(r, l) for (int i = r; i >= l; i--)

using pii = pair<int, int>;
using i64 = int64_t;

mt19937_64 rnd(time(0));

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

// int fac[N], inv[N];
int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
/*
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= 2e5; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[200000] = qpow(fac[200000], mod - 2);
    for (int i = 199999; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int C(int n, int m)
{
    if (n < m || m < 0)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
*/

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define ok cout << "YES\n"
#define no cout << "NO\n"

int fid[N];

int root(int x)
{
    if (x != fid[x])
    {
        fid[x] = root(fid[x]);
    }
    return fid[x];
}

void merge(int x, int y)
{
    int xx = root(x), yy = root(y);
    if (xx != yy)
    {
        fid[xx] = yy;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    rep(2, n)
    {
        int x;
        cin >> x;
        g[x].emplace_back(i);
    }
    auto dfs = [&](auto &self, int u) -> pii {
        if(g[u].size() == 0)return {1,1};
        
        int v1=0,v0=1;//剩下几个不知道

        for(auto &q : g[u]){
            auto [x1,x0]=self(self,q);
            // dfs去找之前的->dp[i][1]和dp[i][0]
            v1 = (1ll*v0*x1 + 1ll*v1*x0)%mod;//1就是1和0 or 0和1
            v0 = 1ll*v0*x0%mod;//要保证都是0就是0和0结合
        }

        return { v1 , (v0+v1)%mod };
    };
    int ans = dfs(dfs, 1).second;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
