void Solve() {
    int n;cin >> n;
    vector<int> f(n + 1);for (int i = 1;i <= n;i++) cin >> f[i];
    vector<int> g(n + 1), h(1e5 + 10);
    int m = 0;
    for (int i = 1;i <= n;i++) {
        if (!g[f[i]]) {
            g[f[i]] = ++m, h[m] = f[i], g[i] = m;
        }
        else if (h[g[f[i]]] == f[i]) g[i] = g[f[i]];
        else return cout << "-1" << endl, void();
    }
    cout << m << endl;
    for (int i = 1;i <= n;i++) cout << g[i] << " \n"[i == n];
    for (int i = 1;i <= m;i++) cout << h[i] << " \n"[i == m];
}
