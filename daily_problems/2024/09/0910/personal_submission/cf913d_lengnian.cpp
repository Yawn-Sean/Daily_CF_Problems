

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    pair<int, pii> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi >> arr[i].se.fi;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i].se.se = i + 1;
    }

    vector<pii> ans;

    int l = 0;
    int r = n;
    while (l <= r)
    {
        int mid = l + r >> 1;
        vector<pii> val;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].fi >= mid)
                val.pb(arr[i].se);
        }
        if (val.size() < mid)
        {
            r = mid - 1;
            continue;
        }

        sort(all(val));

        while (val.size() > mid)
            val.pop_back();
        int tot = 0;
        for (int i = 0; i < mid; i++)
        {
            tot += val[i].fi;
        }
        if (tot > t)
        {
            r = mid - 1;
            continue;
        }
        l = mid + 1;
        if (ans.size() < mid)
            ans = val;
    }

    cout << ans.size() << "\n"
         << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].se << " ";
    }
    return 0;
}
