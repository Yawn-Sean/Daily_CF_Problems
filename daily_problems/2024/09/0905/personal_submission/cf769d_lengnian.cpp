signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        c[x]++;
    }
    for (int i = 0; i < N; i++)
        pop[i] = __builtin_popcount(i);
    i64 res = 0;
    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (pop[i ^ j] == k)
            {
                res += (i == j ? c[i] * 1LL * (c[i] - 1) / 2 : c[i] * 1LL * c[j]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
