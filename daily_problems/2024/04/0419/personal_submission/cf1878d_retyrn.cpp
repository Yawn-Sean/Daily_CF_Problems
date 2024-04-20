int n, m, q;
string s;

void solve() {
    cin >> n >> m;
    cin >> s;
    
    vector<pii> segs;
    vector<int> L(m), R(m);
    for (int i = 0; i < m; i ++) {
        cin >> L[i];
        L[i] --;
    }
    for (int i = 0; i < m; i ++) {
        cin >> R[i];
        R[i] --;
    }
    for (int i = 0; i < m; i ++) {
        segs.emplace_back(L[i], R[i]);
    }
    vector<vector<pii>> b(m, vector<pii>());
    cin >> q;
    
    while (q --) {
        int x;
        cin >> x;
        x --;
        auto it = upper_bound(all(segs), mpr(x, inf));
        it --;
        int t1 = it->fi + it->se - x, t2 = x;
        if (t1 > t2) swap(t1, t2);
        b[it - segs.begin()].push_back(mpr(t1, t2));
    }
    
    for (auto& vec : b) {
        sort(all(vec));
    }
    
    vector<int> d(n + 5, 0);
    for (int i = 0; i < m; i ++) {
        if (em(b[i])) continue;
        int l = L[i], r = R[i];
        // init
        for (int i = l; i <= r + 1; i ++) d[i] = 0;
        
        for (auto [x, y] : b[i]) {
            d[x] += 1;
            d[y + 1] -= 1;
        }
        for (int i = l + 1; i <= r; i ++) d[i] += d[i - 1];
        for (int i = l, j = r; i < j; i ++, j --) {
            if (d[i] & 1) swap(s[i], s[j]);
        }
    }
    cout << s << endl;
}