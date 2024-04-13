void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<vector<int>> e(n);
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s ^= a[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (s == 0)
    {
        cout << "YES" << '\n';
        return;
    }
    if (k == 2)
    {
        cout << "NO" << '\n';
        return;
    }

    int cnt = 1;
    auto dfs = [&](auto self, int u, int fa) -> int
    {
        int sum = a[u];
        for (auto v : e[u])
        {
            if (v == fa)
                continue;
            sum ^= self(self, v, u);
        }
        if (sum == s)
        {
            cnt++;
            return 0;
        }

        return sum;
    };

    dfs(dfs, 0, -1);
    if (cnt >= 3)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
}
