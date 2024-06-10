int n, m, k, r, c;

void solve() {
    cin >> n >> m >> k >> r >> c;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll res = 0;
    if (x1 == x2 and y1 == y2) res = powmod(k, (ll)n * m);
    else res = powmod(k, (ll)n * m - (ll)r * c);
    cout << res << endl;
}