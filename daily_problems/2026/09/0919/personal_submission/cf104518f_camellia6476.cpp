#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
using i64 = long long;

constexpr int N = 3e5 + 10;
constexpr int M = 5e5 + 10;

struct node
{
    int u = 0;
    int v = 0;
    i64 w = 0;

    bool operator< (const node& other) const
    {
        return w < other.w;
    }
}edge[M];

int n, m, pa[N];

int find(int x)
{
    if (x == pa[x])
        return x;
    pa[x] = find(pa[x]);
    return pa[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    iota(pa, pa + 1 + n, 0);
    for (int i = 1; i <= m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    sort(edge + 1, edge + 1 + m);
    i64 ans = 0;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        auto& [x, y, w] = edge[i];
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            g[x].push_back(y);
            g[y].push_back(x);
            pa[px] = py;
            ans += w;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    cout << ans * 2 << '\n' << 2 * n - 1 << '\n';
    auto dfs = [&] (auto&& self, int pos, int fa) -> void
    {
        cout << pos << ' ';
        for (auto& nxt : g[pos])
        {
            if (nxt != fa)
            {
                self(self, nxt, pos);
                cout << pos << ' ';
            }
        }
    };
    dfs(dfs, 1, 0);
    return 0;
}