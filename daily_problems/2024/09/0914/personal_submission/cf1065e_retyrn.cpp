int n, m, a;

void solve() {
    cin >> n >> m >> a;
    vector<int> b(m);
    cin >> b;
    int last = 1;
    Z res = 1;
    for (auto x : b) {
        int k = x - last + 1;
        Z t = power(Z(a), k) + 1;
        res *= t * (t - 1) / 2;
        last = x + 1;
    }
    res *= power(Z(a), n - b.back() * 2);
    cout << res << endl;
}