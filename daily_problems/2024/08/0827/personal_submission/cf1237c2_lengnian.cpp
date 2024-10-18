signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        px[x[i]].pb(vector<int>{y[i], z[i], i + 1});
    }
    for (auto &p : px)
    {
        solve2(p.se);
    }
    for (int i = 0; i + 1 < (int)mr.size(); i += 2)
    {
        ret.pb(mp(mr[i].se, mr[i + 1].se));
    }
    for (auto p : ret)
    {
        cout << p.fi << " " << p.se << "\n";
    }
}
