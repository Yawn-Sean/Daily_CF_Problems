int l, r, x, y;

void solve() {
    cin >> l >> r >> x >> y;
    // ax * bx == x * y
    // abx = y
    if (y % x) {
        cout << 0 << endl;
        return;
    }
    y /= x;
    // ab = y
    int res = 0;
    
    auto check = [&](int x1, int x2) {
        if (gcd(x1, x2) > 1) return false;
        x1 *= x;
        x2 *= x;
        return l <= x1 and x1 <= r and l <= x2 and x2 <= r;
    };
    
    for (int i = 1; i <= y / i; i ++) {
        if (y % i) continue;
        if (check(i, y / i)) res += 1 + (i != y / i);
    }
    cout << res << endl;
}