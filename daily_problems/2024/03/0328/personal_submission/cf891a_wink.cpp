void solve()
{
    int n;
    cin >> n;

    int cnt = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            cnt++;
        }
    }

    SparseTable st(a);
    if (st.query(0, n - 1) != 1)
    {
        cout << -1 << '\n';
        return;
    }
    if (cnt)
    {
        cout << (n - cnt) << '\n';
        return;
    }

    int ans = n;
    for (int i = 0; i < n; ++i)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (st.query(i, mid) == 1)
                r = mid;
            else
                l = mid + 1;
        }
        if (st.query(i, r) == 1)
        {
            ans = min(ans, r - i);
        }
    }

    cout << (n - 1 + ans) << '\n';
}
