void solve()
{
    int n;
    cin >> n;
    // vv(int, g, n + 1);
    vector<vector<int>> g(n + 1);
    vc<int> c(n + 1), s(n + 1, 1);
    s[0] = 0;
    fo(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int cnt = 0;
    auto dfs = [&](auto self, int u, int fa) -> void
    {
        cnt += c[u];
        for (auto v : g[u])
        {
            if (v != fa)
            {
                c[v] = c[u] ^ 1;

                self(self, v, u);
                s[u] += s[v];
            }
        }
    };
    dfs(dfs, 1, 0);

    ll ans = 1ll * cnt * (n - cnt);
    for (auto x : s)
    {
        ans += 1ll * x * (n - x);
    }
    ans /= 2;
    ca;
}
