#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> size(n, 1);
    vector<int> depth(n);

    i64 res = 0;
    function<void(int, int)> dfs = [&](int u, int p)
    {
        for (auto v : adj[u])
        {
            if (v != p)
            {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                res += (long long)size[v] * (n - size[v]);
                size[u] += size[v];
            }
        }
    };

    dfs(0, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (depth[i] & 1)
        {
            cnt++;
        }
    }

    res += (long long)cnt * (n - cnt);
    cout << (res >> 1) << "\n";
    return 0;
}
