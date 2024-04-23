const int N = 1e5 + 10;
vector<PII> g[N];
vector<int> x(N), y(N), w(N);
vector<int> p(N), sz(N, 1);
int n, m;

void dfs(int u, int fa) {
    p[u] = fa;
    for (auto [v, w]: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

ll work(int u, int v, int val) {
    if (p[u] == v) swap(u, v);
    ll c1 = sz[v], c2 = n - sz[v];
    ll ans = c1 * c2 * (c2 - 1) + c2 * c1 * (c1- 1);
    return ans * val;
}

void solve(int _) 
{
    
    cin >> n;
    for (int i = 1; i < n; i ++ ) {
        cin >> x[i] >> y[i] >> w[i];
        g[x[i]].emplace_back(y[i], w[i]);
        g[y[i]].emplace_back(x[i], w[i]);
    }

    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i < n; i ++ ) {
        ans += work(x[i], y[i], w[i]);
    }

    cin >> m;
    ll tmp = (ll) n * (n - 1) * (n - 2) / 6;
    while (m --) {
        int a, b;
        cin >> a >> b;
        ans -= work(x[a], y[a], w[a]);
        w[a] = b;
        ans += work(x[a], y[a], w[a]);
        cout << fixed << setprecision(8) << ans / tmp << endl; 
    }
}  