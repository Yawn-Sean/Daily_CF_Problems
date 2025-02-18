void solve() {
    ll k, base = 9;
    cin >> k;
    vl s(13);
    rep (i, 1, 13) {
        s[i] = s[i-1] + base * i;
        base *= 10;
    }
    int p = lower_bound(all(s), k) - s.begin() - 1;
    k -= s[p];
    ll val = (k + p) / (p + 1);
    if (p) {
        base = 0;
        rep (i, 0, p) base = base * 10 + 9;
        val += base;
    }
    string vs = to_string(val);
    cout << vs[(k - 1) % (p + 1)] << endl;
}
