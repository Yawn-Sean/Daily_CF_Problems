int n;

void solve() {
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    vector<ll> f(n, -inf2);
    f[n - 1] = a[n];
    for (int i = n - 2; i > 0; i --) {
        f[i] = max(f[i + 1], a[i + 1] - f[i + 1]);
    }
    cout << f[1] << endl;
}