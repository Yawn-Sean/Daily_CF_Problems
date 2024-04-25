int n;

void solve() {
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i ++) {
        cin >> f[i];
        f[i] --;
    }
    // f(f(x)) = f(x)
    for (int i = 0; i < n; i ++) {
        if (f[f[i]] != f[i]) {
            cout << -1 << endl;
            return;
        }
    }
    auto h = f;
    sort(all(h));
    complete_unique(h);
    int m = sz(h);
    
    // 先满足g(h(x))的关系
    vector<int> g(n, -1);
    for (int i = 0; i < m; i ++) {
        g[h[i]] = i;
    }
    
    // 存在未设置的g 考虑h(g(x)) = f(x)
    vector<int> pos(n, -1);
    for (int i = 0; i < m; i ++) {
        pos[h[i]] = i;
    }
    for (int i = 0; i < n; i ++) {
        if (g[i] < 0) {
            g[i] = pos[f[i]];
        }
    }
    
    cout << m << endl;
    for (int i = 0; i < n; i ++) {
        cout << g[i] + 1 << ' ';
    }
    cout << endl;
    for (int i = 0; i < m; i ++) {
        cout << h[i] + 1 << ' ';
    }
    cout << endl;
}