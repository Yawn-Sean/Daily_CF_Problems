int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<pii>> g(n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        x --;
        g[x].emplace_back(i, y);
        g[i].emplace_back(x, y);
    }
    
    vector<int> size(n);
    
    auto dfs1 = [&](auto&& self, int u, int fa) -> void {
        size[u] = 1;
        for (auto [x, w] : g[u]) {
            if (x == fa) continue;
            self(self, x, u);
            size[u] += size[x];
        }
    };
    
    dfs1(dfs1, 0, -1);
    
    int res = 0;
    multiset<ll> S = {0};
    auto dfs2 = [&](auto&& self, int u, int fa, ll cur) -> void {
        auto mn = *S.begin();
        if (cur - mn > a[u]) {
            res += size[u];
            return;
        }
        S.insert(cur);
        for (auto [x, w] : g[u]) {
            if (x == fa) continue;
            self(self, x, u, cur + w);
        }
        S.erase(S.find(cur));
    };
    
    for (auto [x, w] : g[0]) {
        dfs2(dfs2, x, 0, w);
    }
    
    cout << res << endl;
}