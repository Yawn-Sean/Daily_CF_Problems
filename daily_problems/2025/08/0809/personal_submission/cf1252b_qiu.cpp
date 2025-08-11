#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> e[N];
int dp[N][3]; // 0:两个子节点连线，1：没连，2：满足条件
void dfs(int u, int fa)
{
    int ve[3] = {1, 0, 0};
    int s1 = 0, s2 = 1;
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        ve[2] = (ve[2] * dp[v][2] % mod + ve[1] * dp[v][1] % mod) % mod;
        ve[1] = (ve[1] * dp[v][2] % mod + ve[0] * dp[v][1] % mod) % mod;
        ve[0] = ve[0] * dp[v][2] % mod;
        s1 = (s1 * dp[v][0] % mod + s2 * dp[v][1] % mod) % mod;
        s2 = s2 * dp[v][0] % mod;
    }
    dp[u][0] = ve[2];
    dp[u][1] = (ve[1] + s2) % mod;
    dp[u][2] = ((dp[u][0] + s1) % mod + s2) % mod;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1][2] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}