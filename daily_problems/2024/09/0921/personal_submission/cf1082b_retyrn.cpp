int n;
string s;

void solve() {
    cin >> n >> s;
    vector<pii> segs;
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'S') continue;
        if (sz(segs) and s[i] == s[i - 1]) segs.back().se += 1;
        else segs.emplace_back(i, i);
        cnt += 1;
    }
    if (em(segs)) {
        cout << 0 << endl;
        return;
    }
    int res = (segs.back().se - segs.back().fi + 1) + (sz(segs) > 1);
    for (int i = 0; i + 1 < sz(segs); i ++) {
        if (segs[i].se + 2 == segs[i + 1].fi) {
            chmax(res, segs[i].se - segs[i].fi + segs[i+1].se - segs[i+1].fi + 3);
        }
        chmax(res, segs[i].se - segs[i].fi + 1 + (sz(segs) > 1));
    }
    chmin(res, cnt);
    cout << res << endl;
}