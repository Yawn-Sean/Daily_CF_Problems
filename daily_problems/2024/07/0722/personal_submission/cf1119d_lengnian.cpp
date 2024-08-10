signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int s[N];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    sort(s + 1, s + n + 1);
    s[n + 1] = INF;
    int a[N], sum[N];
    for (int i = 1; i <= n; i++)
        a[i] = s[i + 1] - s[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int q;
    cin >> q;
    int res[N];
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        r -= l, r++;
        int ans = 0;
        if (a[1] > r)
            ans = 1ll * n * r;
        else
        {
            int ls = 1, rs = n;
            while (ls < rs)
            {
                int mid = (ls + rs) >> 1;
                if (a[mid + 1] <= r)
                    ls = mid + 1;
                else
                    rs = mid;
            }
            ans = 1ll * (n - ls) * r;
            ans += sum[ls];
        }
        res[i] = ans;
    }
    for (int i = 1; i <= q; i++)
        cout << res[i] << " ";
    return 0;
}
