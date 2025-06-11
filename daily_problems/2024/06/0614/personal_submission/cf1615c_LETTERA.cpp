void solve()
{
    // n==1
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    fo(i, 0, n)
    {
        if (a[i] == '1')
        {
            cnt1++;
        }
        if (b[i] == '1')
            cnt2++;
    }
    int ans = n + 3;
    if (cnt1 == cnt2)
    {
        int res = 0;
        fo(i, 0, n)
        {
            if (a[i] != b[i])
            {
                res++;
            }
        }
        ans = min(ans, res);
    }
    if (cnt2 == n - cnt1 + 1)
    {
        int res = 0, f = 0;
        fo(i, 0, n)
        {
            if (a[i] == b[i])
            {
                res++;
                f |= (a[i] == '1');
            }
        }
        ans = min(ans, res + 2 - f * 2);
    }
    cout << (ans == n + 3 ? -1 : ans) << "\n";
}
