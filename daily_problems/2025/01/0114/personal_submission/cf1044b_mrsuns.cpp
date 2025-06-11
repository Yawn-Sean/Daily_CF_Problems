void Solve() {
    int n;cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis1(n + 1), vis2(n + 1);
    int k1, k2;
    cin >> k1;vector<int> a(k1);
    for (int i = 0;i < k1;i++) cin >> a[i], vis1[a[i]] = 1;
    cin >> k2;vector<int> b(k2);
    for (int i = 0;i < k2;i++) cin >> b[i], vis2[b[i]] = 1;
    auto ask = [&](int x) {
        cout << "B " << x << endl;
        int ret;cin >> ret;
        return ret;
        };
    auto ask2 = [&](int x) {
        cout << "A " << x << endl;
        int ret;cin >> ret;
        return ret;
        };
    int x = ask(b[0]);
    if (vis1[x]) {
        return cout << "C " << x << endl, void();
    }
    else {
        vector<int> vis(n + 1);
        vis[x] = 1;
        queue<int> q;q.push(x);
        while (q.size()) {
            auto u = q.front();q.pop();
            if (vis1[u]) {
                int y = ask2(u);
                if (vis2[y]) {
                    cout << "C " << u << endl;
                }
                else {
                    cout << "C " << -1 << endl;
                }
                return;
            }
            for (auto v : g[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << "C " << -1 << endl;
 
}
