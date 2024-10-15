int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (m == 0) {
        ll res = (ll)n * (n - 1) * (n - 2) / 6;
        cout << 3 << ' ' << res << endl;
        return;
    }
    
    vector<int> size(n);
    vector<int> st(n);
    bool odd_ring = false;
    vector<int> cnt(3);
    
    function<void(int, int)> dfs = [&](int u, int c) {
        if (odd_ring) return;
        st[u] = c;
        cnt[c] += 1;
        
        for (auto x : g[u]) {
            if (st[x]) {
                if (st[x] == c) {
                    odd_ring = true;
                    return;
                }
            }
            else {
                dfs(x, 3 - c);
            }
        }
    };
    
    ll res = 0;
    for (int i = 0; i < n; i ++) {
        if (st[i]) continue;
        fill(all(cnt), 0);
        dfs(i, 1);
        if (odd_ring) {
            cout << 0 << ' ' << 1 << endl;
            return;
        }
        size[i] = cnt[1] + cnt[2];
        res += (ll)(cnt[1] - 1) * cnt[1] / 2 + (ll)(cnt[2] - 1) * cnt[2] / 2;
    }
    
    if (*max_element(all(size)) <= 2) {
        cout << 2 << ' ' << (ll)m * (n - 2) << endl;
        return;
    }
    
    cout << 1 << ' ' << res << endl;
}