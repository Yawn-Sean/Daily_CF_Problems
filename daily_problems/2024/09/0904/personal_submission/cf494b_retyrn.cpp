int n, m;
string s, t;

void solve() {
    cin >> s >> t;
    n = sz(s);
    m = sz(t);
    string ss = t + s;
    
    auto z = z_function(ss);
    vector<int> pos(n + 1);
    for (int i = m; i <= n; i ++) {
        if (z[i] >= m) pos[i] = i - m + 1;
        else pos[i] = pos[i - 1];
    }
    vector<Z> f(n + 1, 0), g(n + 1, 0);
    // f[i]前i个字母的合法方案数
    // g[i]前缀和
    
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i - 1];
        if (pos[i]) {
            f[i] += pos[i];
            f[i] += g[pos[i] - 1];
        }
        g[i] = g[i - 1] + f[i];
    }
    cout << f[n] << endl;
}