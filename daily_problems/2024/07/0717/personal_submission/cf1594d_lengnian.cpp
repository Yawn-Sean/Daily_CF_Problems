#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::string c;
        std::cin >> u >> v >> c;
        u--, v--;
        int x = (c == "imposter");
        adj[u].emplace_back(v, x);
        adj[v].emplace_back(u, x);
    }

    std::vector<int> f(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == -1)
        {
            std::queue<int> q;
            q.push(i);
            f[i] = 0;
            std::array<int, 2> cnt{};

            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                cnt[f[x]] += 1;
                for (auto [y, w] : adj[x])
                {
                    if (f[y] == -1)
                    {
                        f[y] = f[x] ^ w;
                        q.push(y);
                    }
                    else if (f[y] != (f[x] ^ w))
                    {
                        ans = -1;
                    }
                }
            }
            if (ans != -1)
            {
                ans += std::max(cnt[0], cnt[1]);
            }
        }
    }
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
