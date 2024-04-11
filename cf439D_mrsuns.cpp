void Solve(int TIME) {

    int n, m;cin >> n >> m;
    vi a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vi b(m + 1);for (int i = 1;i <= m;i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vi pb(m + 1);for (int i = 1;i <= m;i++) pb[i] = pb[i - 1] + b[i];
    vi pa(n + 1);for (int i = 1;i <= n;i++) pa[i] = pa[i - 1] + a[i];
    auto sum = [&](const vi& pre, int l, int r) {
        if (l > r) return 0ll;
        return pre[r] - pre[l - 1];
        };
    int res = inf;
    for (int i = 1;i <= n;i++) {
        auto p = upper_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        if (p == m + 1) res = min(res, i * a[i] - sum(pa, 1, i));
        else res = min(res, i * a[i] - sum(pa, 1, i) + sum(pb, p, m) - (m - p + 1) * a[i]);
        debug(res);debug(p);
    }

    for (int i = 1;i <= m;i++) {
        auto p = lower_bound(a.begin() + 1, a.end(), b[i]) - a.begin() - 1;
        res = min(res, sum(pb, i, m) - (m - i + 1) * b[i] + p * b[i] - sum(pa, 1, p));
    }
    cout << res << endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    PreWork();

    int T = 1;
    //cin >> T;

    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }

    return 0;
}
