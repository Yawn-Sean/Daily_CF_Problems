int n, m;

void solve() {
    cin >> n >> m;
    if ((ll)n * (n - 1) / 2 == m) {
        cout << "NO" << endl;
        return;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    vector<int> res1(n), res2(n);
    
    int A = -1, B = -1;
    for (int i = 0; i < n; i ++) {
        if (sz(g[i]) == n - 1) continue;
        A = i;
        vector<bool> st(n, false);
        for (auto x : g[i]) {
            st[x] = true;
        }
        st[i] = true;
        for (int j = 0; j < n; j ++) {
            if (!st[j]) {
                B = j;
                break;
            }
        }
        break;
    }
    
    res1[A] = n - 1, res1[B] = n;
    res2[A] = res2[B] = n;
    
    int idx = 1;
    for (int i = 0; i < n; i ++) {
        if (res1[i]) continue;
        res1[i] = res2[i] = idx ++;
    }
    
    cout << "YES" << endl;
    cout << res1 << endl << res2 << endl;
}