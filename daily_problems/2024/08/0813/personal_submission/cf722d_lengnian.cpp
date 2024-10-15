signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = 1 << 30;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    check(r);
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    puts("");
    return 0;
}
