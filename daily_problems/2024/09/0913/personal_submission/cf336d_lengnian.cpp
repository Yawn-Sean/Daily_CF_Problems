
void work(int n, int m, int g)
{
    for (;;)
    {
        if (n < 0 || m < 0)
            return;
        if (n + m == 1)
        {
            if (g && m || !g && n)
                ans = (ans + 1) % mod;
            return;
        }
        if (g == 0)
            ans = (ans + C(n, m - 1)) % mod, n--, g = 1;
        else
            n--, g = 0;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, g;
    cin >> n >> m >> g;
    a[0] = 1;
    for (int i = 1; i <= n + m; i++)
        a[i] = a[i - 1] * i % mod;
    for (int i = 0; i <= n + m; i++)
    {
        b[i] = pow(a[i], mod - 2);
    }

    work(n, m, g);
    cout << ans << "\n";

    return 0;
}
