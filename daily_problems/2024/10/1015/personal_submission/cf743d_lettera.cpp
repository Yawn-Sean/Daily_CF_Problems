#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const ll inf = 1E18;
const int N = 2E5 + 5;
vector<int> g[N];
int dp1[N], dp2[N], dp[N], a[N], ans = -inf;
void chmax(int &a, int b)
{
    a = max(a, b);
}
void dfs(int u, int fa)
{
    dp[u] += a[u];
    for (auto v : g[u])
    {
        // dp[i]表示i所在子树的点权和
        if (v != fa)
        {
            dfs(v, u);
            dp[u] += dp[v];
        }
    }
    int x = max(dp[u], dp1[u]);
    if (x >= dp1[fa])
    {
        dp2[fa] = dp1[fa];
        dp1[fa] = x;
    }
    else
    {
        chmax(dp2[fa], x);
    }
    if (dp2[u] > -inf)
    {
        chmax(ans, dp1[u] + dp2[u]);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp1[i] = dp2[i] = -inf;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
   if(ans==-inf)
   {
   	cout<<"Impossible\n";
   }
   else
   {
   	cout<<ans<<"\n";
   }
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
