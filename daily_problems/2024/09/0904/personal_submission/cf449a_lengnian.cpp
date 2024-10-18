void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    if (k > (n - 1) + (m - 1))
    {
        cout << -1 << "\n";
        return;
    }
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        int x = max(0ll, r - 1);
        x = min(x, k);
        int y = n / (x + 1), z = m / (k - x + 1);
        ans = max(ans, y * z);
    }

    cout << ans;
}
