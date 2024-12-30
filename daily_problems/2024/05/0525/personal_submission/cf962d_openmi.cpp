void solve() {
    int n;
    ll x;
    cin >> n;
    map<ll, int> mp;
    rep (i, 1, n + 1) {
        cin >> x;
        while (mp[x] != 0) {
            mp[x] = 0;
            x <<= 1;
        }
        mp[x] = i;
    }
    vc<pil> vp;
    for (auto& [v, i]: mp) {
        if (i) vp.emplace_back(make_pair(i, v));
    }
    cout << vp.size() << nl;
    sort(all(vp));
    for (auto&[_, v]: vp) {
        cout << v << ' ';
    }
}
