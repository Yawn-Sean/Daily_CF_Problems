void solve()
{
    int n, u;
    cin >> n >> u;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    double ans = 0;
    for (int i = 0, k = 0; i < n; ++i)
    {
        while (k < n && a[k] - a[i] <= u)
        {
            k++;
        }

        if (k - i >= 3)
        {
            ans = max(ans, 1.0 * (a[k - 1] - a[i + 1]) / (a[k - 1] - a[i]));
        }
    }

    if (ans <= 0)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
