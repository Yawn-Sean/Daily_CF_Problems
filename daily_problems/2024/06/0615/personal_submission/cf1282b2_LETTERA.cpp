void solve()
{
    // 1ll
    int n, p, k;
    cin >> n >> p >> k;
    vc<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(all(a));
    vc<int> dp(n + 1, 0); // min cost buyying i objs
    fo(i, 1, k)
    {
        dp[i] = dp[i - 1] + a[i - 1];
    }
    fo(i, k, n + 1)
    {
        dp[i] = dp[i - k] + a[i - 1];
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i] <= p)
        {
            ans = i;
            break;
        }
    }
    ca;
}
