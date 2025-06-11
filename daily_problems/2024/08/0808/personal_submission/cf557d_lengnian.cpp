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

void dfs(int x, const vector<vector<int>> &a,
         vector<char> &used, vector<int> &color, vector<int> &comps)
{
    used[x] = 1;
    comps.pb(x);

    for (auto dest : a[x])
        if (!used[dest])
        {
            color[dest] = color[x] ^ 1;
            dfs(dest, a, used, color, comps);
        }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<int> color(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    vector<char> used(n + 1);
    vector<vector<int>> cmps;

    vector<int> comps;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            comps.clear();
            dfs(i, a, used, color, comps);
            cmps.pb(comps);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto x : a[i])
        {
            if (color[i] == color[x])
            {
                cout << "0 1" << "\n";
                return 0;
            }
        }
    }
    if (m == 0)
    {
        int ans = n * (n - 1) * (n - 2) / (long long)6;
        cout << 3 << " " << ans << "\n";
        return 0;
    }
    bool st = false;
    int ans = 0;
    for (int i = 0; i < (int)cmps.size(); i++)
    {
        int h[2];
        memset(h, 0, sizeof h);
        for (int x : cmps[i])
            h[color[x]]++;

        if (h[0] >= 2 || h[1] >= 2)
        {
            if (h[0] >= 2)
                ans += h[0] * (h[0] - 1) / 2;
            if (h[1] >= 2)
                ans += h[1] * (h[1] - 1) / 2;
            st = true;
        }
    }

    if (st)
    {
        cout << 1 << " " << ans << endl;
        return 0;
    }
    else
    {
        cout << 2 << " " << (n - 2) * m << endl;
        return 0;
    }

    assert(0);

    return 0;
}
