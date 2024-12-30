void solve() {
    int n;
    cin >> n;
    vc<pii> vp(n + 1);
    rb (i, 1, n) {
        cin >> vp[i].first >> vp[i].second;
    }

    vi ans(n + 1);
    ans[1] = 1;
    int i = 1;
    while (i < n) {
        auto [n1, n2] = vp[ans[i]];
        i += 1;
        if (i == n + 1) break;
        auto [n3, n4] = vp[n1];
        if (n2 != n3 and n2 != n4) {
            ans[i] = n2; ++i;
            if (i == n + 1) break;
            ans[i] = n1;
        } else {
            ans[i] = n1; ++i;
            if (i == n + 1) break;
            ans[i] = n2;
        }
    }
    rb (i, 1, n) cout << ans[i] << ' ';
}
