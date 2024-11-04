ll n, k;

ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}
void solve() {
    cin >> n >> k;
    if (k == 1) {
        cout << "Yes" << endl;
        return;
    }
    if (n == 1) {
        cout << (k <= 2 ? "Yes" : "No") << endl;
        return;
    }
    if (n <= k) {
        cout << "No" << endl;
        return;
    }
    
    ll t = 1;
    for (int i = 1; i <= min(k, 42LL); i ++) {
        t = lcm(i, t);
        if ((n + 1) % t) {
            cout << "No" <<  endl;
            return;
        }
    }
    cout << "Yes" << endl;
}