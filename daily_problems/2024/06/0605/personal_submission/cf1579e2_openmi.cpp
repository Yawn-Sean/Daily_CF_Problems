void solve() {
    int n;
    cin >> n;
    vector<int> ftr(n+1);
    auto get = [&](int x) {
        ll ret = 0;
        for (; x; x -= x & -x) ret += ftr[x];
        return ret;
    };
    auto add = [&](int x, int p) {
        for (; x <= n; x += x & -x) ftr[x] += p;
    };
    vi a(n);
    in(a);
    vi c = a;
    srt(c);
    erase_unique(c);
    map<int, int> mp;
    rep (i, 0, c.size()) {
        mp[c[i]] = i + 1;
    }
    rep (i, 0, n) {
        a[i] = mp[a[i]];
    }
    c = vi(c.size() + 1, 0);
    ll ans = 0, cur = 0;
    for (int x: a) {
        ll ctl = get(x), cntu = c[x];
        ans += min(ctl - cntu, max(0LL, cur - ctl));
        cur ++;
        c[x]++;
        add(x, 1);
    }
    cout << ans << nl;
}
