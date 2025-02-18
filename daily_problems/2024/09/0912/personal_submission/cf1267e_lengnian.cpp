
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            sum[j] += grid[i][j];
        }

    vector<int> ans;
    for (int i = 0; i < m; i++)
        ans.pb(i);

    for (int i = 0; i < n - 1; i++)
    {
        vector<pii> diff;

        for (int j = 0; j < m; j++)
        {
            diff.pb({grid[j][i] - grid[j][n - 1], j});
        }

        sort(diff.begin(), diff.end());

        int x = sum[n - 1] - sum[i];

        vector<int> pos;
        int ios = 0;
        while (x > 0)
        {
            x += diff[ios].fi;
            pos.pb(diff[ios].se);
            ios++;
        }

        if (pos.size() < ans.size())
        {
            ans = pos;
        }
    }
    cout << ans.size() << "\n";
    for (auto v : ans)
    {
        cout << v + 1 << " ";
    }
    cout << "\n";
    return 0;
}
