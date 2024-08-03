int n, h1, h2, w1, w2;

void solve() {
    cin >> n >> h1 >> h2 >> w1 >> w2;
    ll res = 0;
    for (int i = 0; i < 100000; i ++) {
        if ((ll)i * w1 > n) break;
        res = max(res, (ll)i * h1 + (ll)(n - i * w1) / w2 * h2);
    }
    
    for (int i = 0; i < 100000; i ++) {
        if ((ll)i * w2 > n) break;
        res = max(res, (ll)i * h2 + (ll)(n - i * w2) / w1 * h1);
    }
    cout << res << endl;
}