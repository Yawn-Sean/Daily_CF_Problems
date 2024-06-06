int n, q;

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<int> l(maxn, -1), r(maxn, -1);
    for (int i = 0; i < n; i ++) {
        if (l[a[i]] == -1) l[a[i]] = i;
        r[a[i]] = max(r[a[i]], i);
    }
    vector<pii> segs;
    for (int i = 1; i <= 200000; i ++) {
        if (l[i] >= 0) {
            segs.push_back({l[i], r[i]});
        }
    }
    merge(segs);
    map<int, int> mp;
    int res = 0;
    for (int i = 0; i < sz(segs); i ++) {
        int st = segs[i].fi, ed = segs[i].se;
        for (int j = st; j <= ed; j ++) {
            mp[a[j]] ++;
        }
        int mx = 0;
        for (auto [k, v] : mp) {
            mx = max(mx, v);
        }
        res += (ed - st + 1 - mx);
        mp.clear();
    }
    cout << res << endl;
}