void Solve() {
    int n;cin >> n;
    map<int, int> mp;
    vector<array<int, 2>> evt;
    for (int i = 1;i <= n;i++) {
        int l, r;cin >> l >> r;
        evt.push_back({ l,r });
        mp[l] = mp[r] = mp[r + 1] = 1;
    }
    int tot = 0;for (auto& [i, j] : mp) j = ++tot;
    Segtree tr(vector<int>(tot + 1), tot);
    for (auto& [l, r] : evt) l = mp[l], r = mp[r];
    for (auto [l, r] : evt) {
        tr.update(1, 1, tot, l, r, {1});
    }
    for (int i = 0;i < n;i++) {
        auto [l, r] = evt[i];
        if (tr.query(1, 1, tot, l, r).sum > 1) {
            return cout << i + 1 << endl, void();
        }
    }
    cout << -1 << endl;

}
