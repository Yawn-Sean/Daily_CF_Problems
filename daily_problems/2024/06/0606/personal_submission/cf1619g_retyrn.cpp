int n, k;

void solve() {
    cin >> n >> k;
    vector<ai3> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(all(a), [&](ai3& x, ai3& y) {
        if (x[2] == y[2]) return x < y;
        return x[2] < y[2];
    });
    
    vector<int> id(n);
    DSU dsu(n);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        if (a[x][0] == a[y][0]) return a[x][1] < a[y][1];
        return a[x][0] < a[y][0];
    });
    for (int i = 1; i < n; i ++) {
        int ii = id[i-1], jj = id[i];
        if (a[jj][0] == a[ii][0] and a[jj][1] - a[ii][1] <= k) dsu.merge(ii, jj);
    }
    
    sort(all(id), [&](int x, int y) {
        if (a[x][1] == a[y][1]) return a[x][0] < a[y][0];
        return a[x][1] < a[y][1];
    });
    for (int i = 1; i < n; i ++) {
        int ii = id[i-1], jj = id[i];
        if (a[jj][1] == a[ii][1] and a[jj][0] - a[ii][0] <= k) dsu.merge(ii, jj);
    }
    
    vector<bool> st(n, false);
    
    auto check = [&](int len) {
        fill(all(st), false);
        int i = 0;
        for (; i < n and a[i][2] <= len; i ++) {
            auto t = dsu.leader(i);
            st[t] = true;
        }
        int cnt = 0;
        for (; i < n; i ++) {
            auto t = dsu.leader(i);
            if (!st[t]) {
                cnt += 1;
                st[t] = true;
            }
        }
        return cnt <= len + 1;
    };
    
    
    int l = 0, r = 1e9;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}