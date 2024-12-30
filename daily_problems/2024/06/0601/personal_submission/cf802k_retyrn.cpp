using ai3 = array<int, 3>;
int n, k;

void solve() {
    cin >> n >> k;
    vector<vector<pii>> g(n);
    for (int i = 0; i < n - 1; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    
    vector<vector<int>> f(n, vector<int>(2, 0));
    // f[i][0]从i出发回来的权值最大
    // f[i][1]从i出发不用回来的权值最大
    
    function<void(int, int)> dfs = [&](int u, int fa) {
        // 选k-1个点作为回来 1个不回来
        vector<ai3> nxt;
        for (auto [x, c] : g[u]) {
            if (x == fa) continue;
            dfs(x, u);
            nxt.push_back({f[x][0] + c, c, x});
        }        
        
        sort(all(nxt), greater<ai3>());
        for (int i = 0; i < k - 1 and i < sz(nxt); i ++) {
            f[u][0] += nxt[i][0];
        }
    
        // f[u][1]
        for (int i = k - 1; i < sz(nxt); i ++) {
            auto id = nxt[i][2], c = nxt[i][1];
            f[u][1] = max(f[u][1], f[u][0] + f[id][1] + c);
        }
        
        int sum = f[u][0] + (k - 1 < sz(nxt) ? nxt[k - 1][0] : 0);
        for (int i = 0; i < k and i < sz(nxt); i ++) {
            auto id = nxt[i][2];
            f[u][1] = max(f[u][1], sum - f[id][0] + f[id][1]);
        }
    };
    
    dfs(0, -1);
    cout << f[0][1] << endl;
}