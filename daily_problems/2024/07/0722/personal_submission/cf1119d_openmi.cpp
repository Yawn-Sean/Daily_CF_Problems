void solve() {
    int n, m;
    cin >> n;
    vc<ll> vs(n);
    in(vs);
    srt(vs);
    vs.erase(unique(all(vs)), vs.end());
    n = vs.size();
    vc<ll> diff(n - 1);
    rep (i, 0, n - 1) {
        diff[i] = vs[i + 1] - vs[i];
    }
    srt(diff);
    vc<ll> sum(1, 0);
    rep (i, 0, n - 1) {
        sum.push_back(diff[i] + sum.back());
    }
    cin >> m;
    while (m--) {
        ll l, r, d;
        cin >> l >> r;
        d = r - l + 1;
        ll ans = d;
        int p = upper_bound(all(diff), d) - diff.begin();
        ans += sum[p] + d * (n - 1 - p);
        cout << ans << ' ';
    }
}
