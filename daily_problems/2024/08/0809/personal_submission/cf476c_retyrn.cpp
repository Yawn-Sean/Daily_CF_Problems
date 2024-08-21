int a, b;

void solve() {
    cin >> a >> b;
    if (b == 1) {
        cout << 0 << endl;
        return;
    }
    
    ll res = 0;
    for (int t2 = 1; t2 < b; t2 ++) {
        res += (ll)t2 * a % mod + (ll)(1 + a) * a / 2 % mod * t2 % mod * b % mod;
        res %= mod;
    }
    cout << res << endl;
}