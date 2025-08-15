#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005;

vector<PII> e[N];
int w[N];

int ans = 0;
int dp[N][2];
void dfs(int u, int fa)
{
    // dp[u][0]=w[u];
    for (auto [v, val] : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        if (dp[v][0] - val + w[v] >= dp[u][0])
        {
            dp[u][1] = dp[u][0];
            dp[u][0] = dp[v][0] - val + w[v];
        }
        else if (dp[v][0] - val + w[v] > dp[u][1])
        {
            dp[u][1] = dp[v][0] - val + w[v];
        }
    }
    ans = max(ans, dp[u][0] + dp[u][1] + w[u]);
}

void dfs2(int u, int fa, int mx)
{
    ans = max(dp[u][0] + w[u] + mx, ans);
    for (auto [v, val] : e[u])
    {
        if (v == fa)
            continue;
        if (dp[u][0] + val - w[v] == dp[v][0])
        {
            int t = max(dp[u][1] + w[u] - val, mx + w[u] - val);
            dfs2(v, u, t);
        }
        else
        {
            int t = max(dp[u][0] + w[u] - val, mx + w[u] - val);
            dfs2(v, u, t);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}
