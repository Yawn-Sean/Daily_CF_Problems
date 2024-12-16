ll n, k;
ll a, b;

void solve() {
    cin >> n >> k;
    cin >> a >> b;
    ll mx = 0, mn = inf2;
    
    auto cal = [&](ll L) -> void {
        auto t = n * k / std::gcd(L, n * k);
        chmax(mx, t);
        chmin(mn, t);
    };
    
    for (int i = 0; i < n; i ++) {
        cal(i * k + a - b);
        cal(i * k + a + b);
    }
    cout << mn << ' ' << mx << endl;
}