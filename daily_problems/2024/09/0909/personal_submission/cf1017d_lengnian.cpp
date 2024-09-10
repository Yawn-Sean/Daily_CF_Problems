signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        string s;
        int mask = 0;
        cin >> s;
        for (int j = 0; j < n; j++)
            mask += (1 << j) * (s[j] - '0');
        cnt[mask]++;
    }
    int all = (1 << n) - 1;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if ((i & (1 << j)) != 0)
                cost[i] += a[j];
    }
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int k = 0; k < (1 << n); k++)
            ans[mask][min(cost[all ^ k ^ mask], 101)] += cnt[k];
        for (int k = 1; k <= 100; k++)
            ans[mask][k] += ans[mask][k - 1];
    }
    for (int i = 1; i <= q; i++)
    {
        string s;
        int mask = 0, k;
        cin >> s >> k;
        for (int j = 0; j < n; j++)
            mask += (1 << j) * (s[j] - '0');
        cout << ans[mask][k] << "\n";
    }
    return 0;
}
