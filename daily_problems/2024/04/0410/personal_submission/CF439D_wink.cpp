void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1), b(m + 1), sa(n + 1), sb(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 1; i <= n; ++i)
    {
        sa[i] = sa[i - 1] + a[i];
    }

    for (int i = 1; i <= m; ++i)
    {
        sb[i] = sb[i - 1] + b[i];
    }

    ll ans = 1e18;
    for (int i = 1; i <= n; ++i)
    {
        ll p1 = lower_bound(a.begin(), a.end(), a[i]) - a.begin() - 1;
        ll p2 = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
        ans = min(ans, p1 * a[i] - sa[p1] + sb[m] - sb[p2] - (m - p2) * a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        ll p1 = lower_bound(a.begin(), a.end(), b[i]) - a.begin() - 1;
        ll p2 = lower_bound(b.begin(), b.end(), b[i]) - b.begin() - 1;
        ans = min(ans, p1 * b[i] - sa[p1] + sb[m] - sb[p2] - (m - p2) * b[i]);
    }

    cout << ans << '\n';
}
