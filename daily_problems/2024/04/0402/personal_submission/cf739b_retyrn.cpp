int n;
using pli = pair<ll, int>;

void solve() {
    cin >> n;
    vector<int> a(n), fa(n, -1);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<vector<pii>> g(n);
    for (int i = 1; i < n; i ++) {
        int p, w;
        cin >> p >> w;
        p --;
        g[p].push_back({i, w});
        fa[i] = p;
    }
    
    vector<int> d(n, 0); // 差分数组
    vector<ll> s(n, 0); // 前缀和
    
    set<pli> S;
    
    function<void(int, ll)> dfs = [&](int u, ll pre) {
        s[u] = pre;
        // 需要寻找祖先节点中 0 <= pre - t <= a[u]
        // pre - a[u] <= t
        if (u > 0 and s[u] - s[fa[u]] <= a[u]) {
            auto it = S.lower_bound({pre - a[u], -1});
            auto r = it->se;
            d[fa[u]] += 1;
            if (r != 0) d[fa[r]] -= 1;
        }
        S.insert({s[u], u});
        for (auto [x, w] : g[u]) {
            dfs(x, pre + w);
        }
        S.erase({s[u], u});
    };
    dfs(0, 0ll);
    
    // 自下而上对d求和
    vector<int> res(n);
    
    function<int(int)> dfs1 = [&](int u) {
        int ans = d[u];
        for (auto& [x, w] : g[u]) {
            ans += dfs1(x);
        }
        return res[u] = ans;
    };
    dfs1(0);
    cout << res << endl;
}