signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, l, r;
    cin >> t >> l >> r;
    for (int i = 2; i <= r; ++i)
        ip[i] = i;
    for (int i = 2; i * i <= r; ++i)
    {
        if (ip[i] == i)
        {
            for (int j = i * i; j <= r; j += i)
            {
                ip[j] = min(i, ip[j]);
            }
        }
    }

    dp[1] = 0;
    for (int j = 2; j <= r; ++j)
    {
        dp[j] = 1LL * INF * INF;
        for (int x = j; x != 1; x /= ip[x])
        {
            dp[j] = min(dp[j], 1LL * dp[j / ip[x]] * ip[x] + 1LL * ip[x] * (ip[x] - 1) / 2);
        }
    }
    int ans = 0;
    int tt = 1;
    for (int i = l; i <= r; ++i)
    {
        dp[i] %= mod;
        ans += dp[i] * tt;
        tt *= t;
        tt %= mod;
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}
