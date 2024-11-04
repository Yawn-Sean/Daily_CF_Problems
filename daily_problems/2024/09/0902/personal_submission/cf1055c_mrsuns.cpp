void Solve() {
    int la, ra, a;cin >> la >> ra >> a;
    int lb, rb, b;cin >> lb >> rb >> b;
    int g = gcd(a, b);
    if (lb < la) swap(la, lb), swap(ra, rb), swap(a, b);
    int d = lb - la;
    d %= g;
    auto calc = [&](int l1, int r1, int l2, int r2) {
        return max(0LL, min(r2, r1) - max(l2, l1) + 1);
        };
    cout << max(
        calc(la, ra, la + d, la + d + rb - lb),
        calc(la, ra, la + d - g, la + d - g + rb - lb)
    );
}
