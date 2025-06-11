void solve()
{
    int n, m;
    cin >> n >> m;
    vc<int> h(n + 1), nxt(m + 1), to(m + 1);
    vv(int, f, n + 1, n + 1);
    int cnt = 0;
    auto add = [&](int u, int v)
    {
        nxt[++cnt] = h[u];
        to[cnt] = v;
        h[u] = cnt;
    };
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        f[u][v]++;
    }
    ll ans = 0;
    for (int v = 1; v <= n; v++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == v)
                continue;
            int cnt = 0;
            for (int j = h[i]; j; j = nxt[j]) // 两个for加起来复杂度是O(m)
            {
                int u = to[j];
                if (u == v || u == i)
                    continue;
                if (f[u][v])
                {
                    cnt++;
                }
                        }
            ans += 1ll * cnt * (cnt - 1) / 2;
        }
    }

    ca;
}
