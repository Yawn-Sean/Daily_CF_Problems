LL n, k, a, b;

void meibao() {
    cin >> n >> k >> a >> b;
    LL mn = n * k, mx = 0;
    for (int i = 0; i < n; i++) {
        LL x = k * i + a + b;
        LL res = n * k / gcd(x, n * k);
        mn = min(mn, res);
        mx = max(mx, res);

        x = k * i + a - b;
        res = n * k / gcd(n * k, x);
        mn = min(mn, res);
        mx = max(mx, res);
    }
    cout << mn << " " << mx << "\n";
}
