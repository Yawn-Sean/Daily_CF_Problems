int n, p;

int cal(pii& x) {
    int l = x.fi, r = x.se;
    if (l % p) l += (p - l % p);
    if (l > r) return 0;
    return (r - l) / p + 1;
}
void solve() {
    cin >> n >> p;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i ++) {
        pii x;
        cin >> x;
        a[i] = cal(x);
        b[i] = (x.se - x.fi + 1) - a[i];
    }
    // 每一对相互独立
    double res = 0.0;
    for (int i = 0; i < n; i ++) {
        int u = i, v = (i == n - 1 ? 0 : i + 1);
        res += 2000.0 * (1.0 - (double)b[u] * b[v] / (a[u] + b[u]) / (a[v] + b[v]));
    }
    cout << res << endl;
}