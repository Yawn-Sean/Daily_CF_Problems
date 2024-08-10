void Solve() {
    int n;cin >> n;
    vector<vector<int>> v(n + 1);
    vector<int> sz(n + 1, 1), p(n + 1);
    for (int i = 1;i <= n;i++) p[i] = i;
    auto find = [&](auto&& find, int x)->int {
        return x == p[x] ? p[x] : p[x] = find(find, p[x]);
        };
    auto merge = [&](int x, int y) {
        x = find(find, x);
        y = find(find, y);
        if (x == y) return 0;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        for (auto i : v[y]) v[x].push_back(i);
        return 1;
        };
    for (int i = 1;i <= n;i++) p[i] = i, sz[i] = 1;
    for (int i = 1;i <= n;i++) v[i].push_back(i);
    for (int i = 1;i < n;i++) {
        int u, v;cin >> u >> v;
        assert(merge(u, v));
    }
    int t = find(find, 1);
    for (auto i : v[t]) cout << i << ' ';cout << endl;
}
