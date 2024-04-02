void solve()
{
    int n, m;
    cin >> n >> m;

    ll v = 0;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v ^= a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        v ^= b[i];
    }

    // 每个数都出现两次，那 v 最终结果必然为 0，否则无解
    if (v)
    {
        cout << "NO" << '\n';
        return;
    }

    vector<vector<int>> c(n, vector<int>(m, 0));
    for (int i = 1; i < n; ++i)
    {
        c[i][0] = a[i];
    }
    for (int j = 1; j < m; ++j)
    {
        c[0][j] = b[j];
    }
    c[0][0] = a[0];
    for (int j = 1; j < m; ++j)
    {
        c[0][0] ^= b[j];
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
}
