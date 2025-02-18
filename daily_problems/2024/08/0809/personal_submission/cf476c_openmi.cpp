void solve() {
    ll a, b;
    cin >> a >> b;
    cout << ((a + (a * (a + 1) / 2 % mod) * b % mod) % mod) * (b * (b - 1) / 2 % mod) % mod;
}
