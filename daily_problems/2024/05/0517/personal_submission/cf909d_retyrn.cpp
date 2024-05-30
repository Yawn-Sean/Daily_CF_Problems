int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    vector<pii> segs;
    int last = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] != s[last]) {
            segs.emplace_back(s[last] - 'a', i - last);
            last = i;
        }
    }
    segs.emplace_back(s[last] - 'a', n - last);
    
    // 暴力
    int res = 0;
    while (sz(segs) > 1) {
        for (int i = 0; i < sz(segs); i ++) {
            int u = (i == 0 or i == sz(segs) - 1 ? 1 : 2);
            segs[i].se = max(0, segs[i].se - u);
        }
        res += 1;
        vector<pii> nxt;
        for (int i = 0; i < sz(segs); i ++) {
            if (segs[i].se <= 0) continue;
            if (sz(nxt) and nxt.back().fi == segs[i].fi) nxt.back().se += segs[i].se;
            else nxt.push_back(segs[i]);
        }
        segs = move(nxt);
    }
    cout << res << endl;
}