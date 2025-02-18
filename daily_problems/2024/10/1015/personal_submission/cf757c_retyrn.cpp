int n, m;
ll f[maxn];

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(m);
    for (int i = 0; i < n; i ++) {
        int len;
        cin >> len;
        while (len --) {
            int x;
            cin >> x;
            x --;
            g[x].emplace_back(i);
        }
    }
    
    f[0] = 1;
    for (int i = 1; i <= 1000000; i ++) {
        f[i] = f[i - 1] * i % mod;
    }
    sort(all(g));
    
    ll res = 1;
    int cur = 1;
    for (int i = 1; i < m; i ++) {
        if (g[i] == g[i - 1]) cur += 1;
        else {
            res = res * f[cur] % mod;
            cur = 1;
        }
    }
    res = res * f[cur] % mod;
    cout << res << endl;
}