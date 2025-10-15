int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    
    vector<Z> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i-1] * (k + i - 1);
    }
    
    vector<Z> g(n + 1);
    g[0] = 1;
    for (int i = 1; i <= n; i ++) {
        g[i] = g[i-1] * i;
    }
    
    vector<Z> res(n);
    for (int j = 0; j < n; j ++) {
        for (int i = 0; i <= j; i ++) {
            res[j] += f[j-i] / g[j-i] * a[i];
        }
    }
    
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << endl;
}