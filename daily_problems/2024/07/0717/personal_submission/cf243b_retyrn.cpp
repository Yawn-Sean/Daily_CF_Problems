int n, m, h, t;

void solve() {
    cin >> n >> m >> h >> t;
    vector<vector<int>> g(n);
    vector<pii> E;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
        E.emplace_back(x, y);
        E.emplace_back(y, x);
    }
    vector<int> st(n, -1);
    vector<int> ver;
    int start = -1, end = -1;
    
    auto init = [&]() {
        for (auto k : ver) {
            st[k] = -1;
        }
        ver.clear();
    };
    
    for (auto [x, y] : E) {
        vector<int> cnt(3);
        for (auto k : g[x]) {
            if (k == y) continue;
            st[k] = 0;
            cnt[0] += 1;
            ver.push_back(k);
            if (cnt[0] >= h + t) break;
        }
        if (cnt[0] < h) {
            init();
            continue;
        }
        
        for (auto k : g[y]) {
            if (k == x) continue;
            if (st[k] == 0) {
                st[k] = 2;
                cnt[0] -= 1, cnt[2] += 1;
            }
            else {
                st[k] = 1;
                cnt[1] += 1;
                ver.push_back(k);
            }
            if (cnt[0] + cnt[2] >= h and cnt[1] + cnt[2] >= t and cnt[0] + cnt[1] + cnt[2] >= h + t) break;
        }
        if (cnt[0] + cnt[2] >= h and cnt[1] + cnt[2] >= t and cnt[0] + cnt[1] + cnt[2] >= h + t) {
            start = x, end = y;
            break;
        }
        init();
    }
    if (start < 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << start + 1 << ' ' << end + 1 << endl;
    fill(all(st), 0);
    for (auto x : g[start]) {
        if (x == end) continue;
        st[x] |= 1;
    }
    for (auto x : g[end]) {
        if (x == start) continue;
        st[x] |= 2;
    }
    
    vector<int> ans1, ans2;
    for (int i = 0; i < n and sz(ans1) < h; i ++) {
        if (st[i] == 1) {
            ans1.push_back(i + 1);
        }
    }
    for (int i = 0; i < n and sz(ans2) < t; i ++) {
        if (st[i] == 2) {
            ans2.push_back(i + 1);
        }
    }
    for (int i = 0; i < n; i ++) {
        if (st[i] == 3) {
            if (sz(ans1) < h) ans1.push_back(i + 1);
            else if (sz(ans2) < t) ans2.push_back(i + 1);
            else break;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}