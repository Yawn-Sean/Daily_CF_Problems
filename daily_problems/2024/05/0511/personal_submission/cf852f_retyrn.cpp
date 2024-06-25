int n, m, a, Q;

void solve() {
    cin >> n >> m >> a >> Q;
    // phi
    vector<int> p = {1};
    for (int i = 0; i <= 1000123; i ++) {
        ll t = (ll)p.back() * a % Q;
        if (t == 1) break;
        p.push_back(t);
    }
    
    const int phi = sz(p);
    Comb comb(m, phi);
    
    // 指数
    vector<ll> b(n, 1);
    for (int i = 1; i < n; i ++) {
        b[i] = (b[i - 1] + comb.binom(m, i)) % phi;
    }
    for (int i = 0; i < n; i ++) {
        b[i] = p[b[i]];
    }
    reverse(all(b));
    cout << b << endl;
}