signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> res;
    for (int o = 0; o < n; o++)
    {
        if (check(o))
            res.pb(o);
    }
    cout << res.size() << "\n";

    for (int i = 0; i < (int)res.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << res[i] + 1;
    }
    cout << "\n";
    return 0;
}
