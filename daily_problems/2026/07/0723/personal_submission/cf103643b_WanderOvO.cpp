int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


void solve() {
    int n;
    cin >> n;
    set<PII> res;
    for (int i = 1; i <= n; i++) {
        res.clear();
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        res.insert({a + b, 1});
        res.insert({a - b, 1});
        res.insert({b - a, 1});
        res.insert({a * b, 1});
        int aa = a / g, bb = b / g;
        if (bb < 0) {
            bb *= -1;
            aa *= -1;
        }
        res.insert({aa, bb});
        if (aa < 0) {
            aa *= -1;
            bb *= -1;
        }
        res.insert({bb, aa});
        cout << res.size() << "\n";
    }
}
