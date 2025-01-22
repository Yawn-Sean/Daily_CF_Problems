int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    cin >> a;
    
    vector<int> mx(m, 0), cost(m, 0);
    
    for (int i = 0; i < m; i ++) {
        vector<int> p;
        for (int j = 0; j < n; j ++) {
            if (a[j][i]) p.push_back(j);
        }
        int j = 0;
        for (int t = 0; t < sz(p); t ++) {
            while (j < sz(p) and p[j] - p[t] + 1 <= k) j ++;
            if (j - t > mx[i]) {
                mx[i] = j - t;
                cost[i] = t;
            }
        }
    }
    
    int sm = accumulate(all(mx), 0), sc = accumulate(all(cost), 0);
    cout << sm << ' ' << sc << endl;
}