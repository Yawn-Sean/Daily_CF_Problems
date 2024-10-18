void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[v]++;
        deg[u]++;
    }
    int s = count(deg.begin(), deg.end(), 1);

    double ans = 2.0 * k / s;
    cout << ans << '\n';
}
