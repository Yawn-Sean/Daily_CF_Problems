#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
struct DSU
{
    std::vector<int> f, sz;
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        sz.assign(n, 1); // 0
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    vector<array<int, 2>> c(n * m + 1);
    DSU dsu(n * m + 1);
    auto get = [&](int x, int y) { return (x - 1) * m + y; };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            c[(i - 1) * m + j] = {i, j};
        }
    }
    sort(c.begin() + 1, c.end(), [&](array<int, 2> u, array<int, 2> v) { return a[u[0]][u[1]] > a[v[0]][v[1]]; });
    vector<array<int, 2>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (int i = 1; i <= n * m; i++)
    {
        auto [x, y] = c[i];
        for (int j = 0; j < 4; j++)
        {
            auto [dx, dy] = dirs[j];
            int nx = x + dx, ny = y + dy;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[x][y] <= a[nx][ny])
            {
                dsu.merge(get(x, y), get(nx, ny));
            }
        }
        if (k % a[x][y] == 0 && dsu.size(get(x, y)) >= k / a[x][y])
        {
            cout << "YES\n";
            int cnt = k / a[x][y];
            int v = a[x][y];
            auto dfs = [&](auto self, int x, int y) -> void {
                if (!cnt)
                {
                    return;
                }
                cnt--;
                ans[x][y] = v;
                for (int j = 0; j < 4; j++)
                {
                    auto [dx, dy] = dirs[j];
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] >= v && ans[nx][ny] == 0)
                    {
                        self(self, nx, ny);
                    }
                }
            };
            dfs(dfs, x, y);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << ans[i][j] << " \n"[j == m];
                }
            }
            return;
        }
    }
    cout << "NO\n";
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
