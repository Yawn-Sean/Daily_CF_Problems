void solve()
{
    int n, m;
    cin >> n >> m;

    vector<array<int, 4>> e(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--, v--;
        e[i] = {u, v, l, r};
    }

    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int l = e[i][2], r = e[i][3];
        auto check = [&](int mid)
        {
            DSU ds(n);
            for (auto [u, v, ql, qr] : e)
            {
                if (ql <= e[i][2] && qr >= mid)
                {
                    ds.merge(u, v);
                }
            }
            return ds.same(0, n - 1);
        };
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }

        if (check(r))
        {
            ans = max(ans, r - e[i][2] + 1);
        }
    }

    if (ans == 0)
    {
        cout << "Nice work, Dima!" << '\n';
        return;
    }
    cout << ans << '\n';
}
