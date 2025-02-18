int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(m);
    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        a --;
        g[a].push_back(b);
    }
    vector<int> sum(n + 1);
    for (int i = 0; i < m; i ++) {
        sort(all(g[i]), greater<int>());
        int s = 0;
        for (int j = 0; j < sz(g[i]); j ++) {
            s += g[i][j];
            if (s > 0) sum[j + 1] += s;
        }
    }
    
    int res = *max_element(all(sum));
    
    cout << res << endl;
}