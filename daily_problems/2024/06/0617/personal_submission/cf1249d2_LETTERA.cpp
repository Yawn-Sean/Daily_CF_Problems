void solve()
{
    const int N = 2e5 + 5;
    int n, k;
    cin >> n >> k;
    // debug(n);
    //  维护左端点经过i的右端点r按大小排序的数据结构，然后超过r时删除
    vc<int> rs(1); //!!!
    vc<vc<int>> l(N), r(N);
    vc<int> ans;
    fo(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        rs.pb(y);
        l[x].pb(i + 1);
        r[y].pb(i + 1);
    }
    set<PII> s;
    fo(i, 1, 2e5 + 1)
    {
        for (auto &id : l[i])
        {
            s.insert({rs[id], id});
        }
        while (len(s) > k)
        {
            auto [_, id] = *s.rbegin();
            s.erase(*s.rbegin());
            ans.pb(id);
        }
        for (auto &id : r[i])
        {
            if (s.find({i, id}) != s.end())
            {
                s.erase(s.find({i, id}));
            }
        }
    }
    cout << len(ans) << "\n";
    fo(i, 0, len(ans))
    {
        cout << ans[i] << " ";
    }
    cn;
    return;
}
