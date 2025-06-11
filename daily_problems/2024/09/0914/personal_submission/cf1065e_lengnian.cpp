
int qpow(int x, int e)
{
    int ret = 1;
    for (; e; e >>= 1, x = 1ll * x * x % MOD)
        if (e & 1)
            ret = 1ll * ret * x % MOD;
    return ret;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    ans = qpow(k, n - a[m]);
    ans = 1ll * ans * qpow(qpow(2, m), MOD - 2) % MOD;
    for (int i = m; i; i--)
        a[i] -= a[i - 1];
    for (int i = 1; i <= m; i++)
        ans = 1ll * ans * (1 + qpow(k, a[i])) % MOD;
    cout << ans << "\n";
    return 0;
}
