int n, m;
void solve() {
    cin >> n >> m;
    vector<vector<int>> to(n);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if (y < x) y += n;
        to[x].push_back(y);
    }
    vector<ll> need(n, -inf2);
    // k == 0
    for (int i = 0; i < n; i ++) {
        int t = sz(to[i]);
        if (t == 0) continue;
        int mn = *min_element(all(to[i]));
        need[i] = (ll)(t - 1) * n + mn;
    }
    vector<ll> l(n + 1, -inf2), r(n + 1, -inf2);
    for (int i = 1; i <= n; i ++) {
        l[i] = max(l[i-1], need[i-1]);
        r[i] = max(r[i-1], need[n-i]);
    }
    
    vector<ll> res(n);
    res[0] = l[n];
    
    for (int k = 1; k < n; k ++) {
        res[k] = max(l[k] + n - k, r[n-k] - k);
    }
    
    // 0 -> k
    // [0, k-1] 最大值多走n - k, [k, n-1] 最大值少走k
    cout << res << endl;
}