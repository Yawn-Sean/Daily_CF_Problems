void solve()
{
    int n;
    cin >> n;
    vc<double> a(n);
    fo(i, 0, n)
    {
        cin >> a[i];
    }
    sort(all(a), [&](double x, double y)
         { return x > y; });
    double ans = 0;
    double x = 0, y = 1;
    fo(i, 0, n)
    {
        x = x * (1 - a[i]) + y * a[i];
        y *= (1 - a[i]);
        ans = max(ans, x);
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
