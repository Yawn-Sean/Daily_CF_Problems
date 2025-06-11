#define int i64
 
constexpr int inf = 1e18;
 
void solve() {
    int n;
    cin >> n;
    vec<int> a(n);
    for (auto & i : a) cin >> i;
    vec2<int> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    vec<int> s(n);
    auto dfs = [&](auto&& self, int x, int fa) -> void {
        s[x] = a[x];
        for (int y : g[x]) {
            if (y == fa) continue;
            self(self, y, x);
            s[x] += s[y];
        }
    };
    dfs(dfs, 0, -1);
 
    vec2<int> dp(2, vec<int>(n, -inf));
    auto dfs1 = [&](auto&& self, int x, int fa) -> void {
        chmax(dp[0][x], s[x]);
        vec<int> rec;
        for (int y : g[x]) {
            if (y == fa) continue;
            self(self, y, x);
            chmax(dp[0][x], dp[0][y]);
            chmax(dp[1][x], dp[1][y]);
            rec.push_back(dp[0][y]);
        }
        if (rec.size() >= 2) {
            ranges::sort(rec, greater{});
            chmax(dp[1][x], rec[0] + rec[1]);
        }
    };
    dfs1(dfs1, 0, -1);
    int ans = dp[1][0];
 
    if (ans == -inf) {
        cout << "Impossible\n";
        return;
    }
    cout << ans << '\n';
}
