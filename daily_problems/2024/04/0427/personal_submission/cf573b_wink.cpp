void solve()
{
    int n;
    cin >> n;

    vector<int> f(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i];
    }

    f[0] = f[n - 1] = 1;
    for (int i = 1; i < n; ++i)
    {
        f[i] = min(f[i], f[i - 1] + 1);
    }

    for (int i = n - 2; i >= 0; --i)
    {
        f[i] = min(f[i], f[i + 1] + 1);
    }

    cout << *max_element(f.begin(), f.end()) << '\n';
}
