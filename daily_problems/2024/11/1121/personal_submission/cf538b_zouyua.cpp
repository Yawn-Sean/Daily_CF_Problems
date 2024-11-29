void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1);
    vector<vector<ll>> g(n + 1), f(n + 1, vector<ll>(2));
    for(int i = 1; i <= n; i ++) {
        ll p, v; cin >> p >> v;
        a[i] = v;
        if(i == 1) {

        } else {
            g[p].push_back(i);
        }
    }
    auto dfs = [&](auto &&dfs, int u) -> void {

        //cout << u << ' ' << f[u][0] << endl;
        f[u][1] = -INF;
        for(auto &v : g[u]) {
            dfs(dfs, v);
            ll x = f[u][0], y = f[u][1];
            f[u][1] = max(x + f[v][1], y + f[v][0]);
            f[u][0] = max(y + f[v][1], x + f[v][0]);
        }
        ll x = f[u][0], y = f[u][1];
        f[u][1] = max(y, x + a[u]);
    };
    dfs(dfs, 1);
    //cout << f[5][1] << endl;
    cout << max(f[1][1], f[1][0]) << endl;
}
