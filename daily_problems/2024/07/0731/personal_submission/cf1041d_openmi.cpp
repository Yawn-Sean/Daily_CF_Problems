void solve() {
    int n, h, ans = 0;
    cin >> n >> h;
    ans = h;
    vc<pii> vp(n);
    for (auto& p: vp) {
        cin >> p.first >> p.second;
    }
    int l = 0, pre = 0, cur = 0;
    rep (r, 0, n) {
        cur += max(0, vp[r].first - vp[pre].second);
        while (l < r and cur >= h) {
            cur -= vp[l + 1].first - vp[l].second;
            l++;
        }
        pre = r;
        chmax(ans, vp[r].second - vp[l].first - cur + h);
    }
    cout << ans;
}
