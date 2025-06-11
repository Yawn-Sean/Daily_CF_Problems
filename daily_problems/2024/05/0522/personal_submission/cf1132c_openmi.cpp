void solve() {
    int n, q;
    cin >> n >> q;
    vi cnt(n+1), acc(n+1);
    int l, r, ans = 0;
    vc<pii> vp(q);
    rep (i, 0, q) {
        cin >> l >> r;
        vp[i] = {l, r};
        rb (j, l, r) cnt[j] ++;
    }
    
    rep (i, 0, q) {
        auto& [l, r] = vp[i];
        rb (j, l, r) cnt[j]--; 

        int cnt1 = 0;
        rb (j, 1, n) {
            acc[j] = acc[j-1];
            if (cnt[j]) cnt1++;
            if (cnt[j] == 1) acc[j] ++;
        }

        rep (j, i + 1, q) {
            auto& [l2, r2] = vp[j];
            chmax(ans, cnt1 - (acc[r2] - acc[l2 - 1]));
        }

        rb (j, l, r) cnt[j]++;
    }
    cout << ans << nl;
}
