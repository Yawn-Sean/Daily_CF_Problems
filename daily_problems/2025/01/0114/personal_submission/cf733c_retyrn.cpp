int n, m;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    cin >> m;
    vector<int> b(m);
    cin >> b;
    
    if (accumulate(all(a), 0) != accumulate(all(b), 0)) {
        cout << "NO" << endl;
        return;
    }
    
    vector<pii> segs;
    for (int i = 0, last = 0; i < m; i ++) {
        int j = last, cur = 0;
        while (j < n and cur < b[i]) {
            cur += a[j ++];
        }
        if (cur > b[i]) {
            cout << "NO" << endl;
            return;
        }
        segs.emplace_back(last, j - 1);
        last = j;
    }
    
    if (em(segs) or segs.back().se != n - 1) {
        cout << "NO" << endl;
        return;
    }
    
    // check是否存在最大值
    for (const auto& [l, r] : segs) {
        int mx = -inf, mn = inf;
        for (int i = l; i <= r; i ++) {
            chmax(mx, a[i]);
            chmin(mn, a[i]);
        }
        if (l != r and mx == mn) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    int d = 1;
    
    for (auto [l, r] : segs) {
        if (l == r) {
            d += 1;
            continue;
        }
        vector<int> v;
        for (int i = l; i <= r; i ++) {
            v.push_back(a[i]);
        }
        
        while (sz(v) > 1) {
            // 找到吞噬者
            int mx = -inf, who = -1;
            for (int i = 0; i < sz(v); i ++) {
                if ((i - 1 >= 0 and v[i] > v[i-1]) or (i + 1 < sz(v) and v[i] > v[i+1])) {
                    if (v[i] > mx) {
                        mx = v[i];
                        who = i;
                    }
                }
            }
            // dbg(l, r, who, v);
            if (who - 1 >= 0 and v[who] > v[who-1]) {
                cout << who + d << " L" << endl;
                v[who] += v[who - 1];
                v.erase(v.begin() + who - 1);
            }
            else {
                cout << who + d << " R" << endl;
                v[who] += v[who + 1];
                v.erase(v.begin() + who + 1);
            }
        }
        
        d += 1;
    }
    
}