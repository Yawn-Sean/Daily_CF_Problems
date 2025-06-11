
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        a.pb({s, e});
    }
    int ans = 0, cur = 0;
    sort(all(a));
    for (int i = 0; i < n; i++)
    {
        int s = a[i].fi, e = a[i].se;
        auto pos = tv.upper_bound(-1 * s);
        if (pos == tv.end())
        {
            ans = (ans + (x + (y * (e - s)) % MOD) % MOD) % MOD;
        }
        else
        {
            cur = *pos;
            cur = cur * (-1);
            if (y * (e - cur) < x + y * (e - s))
            {
                tv.erase(tv.find(-1 * cur));
                ans = (ans + (y * (e - cur) % MOD) % MOD) % MOD;
            }
            else
            {
                ans = (ans + (x + (y * (e - s)) % MOD) % MOD) % MOD;
            }
        }
        tv.insert(-1 * e);
    }

    cout << ans;

    return 0;
}
