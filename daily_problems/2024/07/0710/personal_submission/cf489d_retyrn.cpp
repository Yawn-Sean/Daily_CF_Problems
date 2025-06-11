int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
    }
    vector<int> cnt(n);
    ll res = 0;
    
    for (int i = 0; i < n; i ++) {
        fill(all(cnt), 0);
        for (auto x : g[i]) {
            for (auto y : g[x]) {
                cnt[y] += 1;
            }
        }
        for (int j = 0; j < n; j ++) {
            if (i == j) continue;
            res += (ll)cnt[j] * (cnt[j] - 1) / 2;
        }
    }
    cout << res << endl;
}