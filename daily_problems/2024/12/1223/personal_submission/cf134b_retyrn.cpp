int n;

int gcd(int x, int y) {
    if (!y) return inf;
    if (y == 1) return x - 1;
    return gcd(y, x % y) + x / y;
}
void solve() {
    cin >> n;
    int res = inf;
    for (int i = 1; i <= n; i ++) {
        chmin(res, gcd(i, n));
    }
    cout << res << endl;
}