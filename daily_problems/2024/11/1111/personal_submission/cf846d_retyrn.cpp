int n, m, k, q;

void solve() {
    cin >> n >> m >> k >> q;
    
    if (q == 0) {
        cout << -1 << endl;
        return;
    }
    
    vector<ai3> a(q);
    for (int i = 0; i < q; i ++) {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
        a[i][1] --;
        a[i][2] --;
    }
    sort(all(a));
    vector<vector<int>> g(n, vector<int>(m));
    
    auto check = [&](int len) -> bool {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                g[i][j] = 0;
            }
        }
        for (auto [t, x, y] : a) {
            if (t > len) break;
            g[x][y] = 1;
        }
        PrefixSum2D<int, int> ps(n, m, g);
        
        for (int i = 1; i + k - 1 <= n; i ++) {
            for (int j = 1; j + k - 1 <= m; j ++) {
                if (ps.sum(i, j, i + k - 1, j + k - 1) == k * k) {
                    return false;
                }
            }
        }
        return true;
    };
    
    int l = 0, r = a[q-1][0];
    
    if (check(r)) {
        cout << -1 << endl;
        return;
    }
    
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << r << endl;
}