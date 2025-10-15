#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;
struct Tarjan
{
    int n, m, idx;
    vector<vector<int>> g;
    vector<int> dfn, low, siz;
    vector<int> is_cut; // 是否为割点
    int ans, sum;

    Tarjan(int n, int m) : n(n), m(m)
    {
        g.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        siz.assign(n + 1, 0);
        is_cut.assign(n + 1, 0);
        idx = 0;
        sum = n * (n - 1) / 2;
        ans = sum;
    }

    void add_edge(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int u, int fa)
    {
        siz[u] = 1;
        dfn[u] = low[u] = ++idx;
        int child = 0; // 记录根节点子树个数
        for (auto v : g[u])
        {
            if (!dfn[v])
            {
                child++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                siz[u] += siz[v];

                // 桥
                if (low[v] > dfn[u])
                {
                    ans = min(ans, sum - siz[v] * (n - siz[v]));
                }

                // 割点判定
                if (fa != 0 && low[v] >= dfn[u])
                {
                    is_cut[u] = 1;
                }
            }
            else if (v != fa)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }

        // 根节点特殊处理
        if (fa == 0 && child > 1)
        {
            is_cut[u] = 1;
        }
    }

    void run()
    {
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
                dfs(i, 0);
        }
    }

    int get_bridge_answer()
    {
        return ans;
    }

    vector<int> get_cut_points()
    {
        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            if (is_cut[i])
                res.push_back(i);
        }
        return res;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    Tarjan tar(n, m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        tar.add_edge(u, v);
    }
    tar.run();
    cout << tar.get_bridge_answer() << endl;
    // cout << ans << endl;
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
