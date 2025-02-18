#define int i64
 
void solve() {
    int n, m;
    cin >> n >> m;
    vec<int> in(n);
    vec2<int> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        in[v]++;
        in[u]++;
    }
 
    vec<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (j <= i) continue;
            chmax(dp[j], dp[i] + 1);
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        chmax(ans, dp[i] * in[i]);
    }
 
    cout << ans << '\n';
}
