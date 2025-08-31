#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

vector<int> e[N];

int dp[N][2];
int ans;
void dfs1(int u, int fa)
{
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        dfs1(v, u);
        if (dp[u][0] <= dp[v][0] + 1 + max(0ll, (int)e[v].size() - 2))
        {
            dp[u][1] = dp[u][0];
            dp[u][0] = dp[v][0] + 1 + max(0ll, (int)e[v].size() - 2);
        }
        else if (dp[u][1] <= dp[v][0] + 1 + max(0ll, (int)e[v].size() - 2))
        {
            dp[u][1] = dp[v][0] + 1 + max(0ll, (int)e[v].size() - 2);
        }
    }
    ans = max(ans, dp[u][0] + dp[u][1] + max(0ll, (int)e[u].size() - 2) + 1);
}

void dfs2(int u, int fa, int len)
{
    ans = max(ans, dp[u][0] + len + 1 + max((int)e[u].size() - 2, 0ll));
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        int newlen;
        if (dp[u][0] == dp[v][0] + 1 + max(0ll, (int)e[v].size() - 2))
        {
            newlen = max(dp[u][1], len) + 1 + max(0ll, (int)e[u].size() - 2);
        }
        else
        {
            newlen = max(dp[u][0], len) + 1 + max(0ll, (int)e[u].size() - 2);
        }

        dfs2(v, u, newlen);
    }
}

void solve()
{
    int n;
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 0;
        e[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    // cout << ans << endl;
    dfs2(1, 0, 0);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    cin >> T;
    while (T--)
        solve();
    return 0;
}
