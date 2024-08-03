int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(m));
    cin >> dist;
    
    vector<int> cnt(n + 2);
    
    Z res = 0;
    
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            cnt[dist[j][i]] += 1;
        }
        
        Z cur = 1;
        int sum = 0;
        for (int j = n + 1; j > 1; j --) {
            sum += cnt[j];
            cur *= sum;
            sum -= 1;
        }
        for (int i = 2; i <= n; i ++) {
            cur /= i;
        }
        res += (1 - cur);
        fill(all(cnt), 0);
    }
    cout << res << endl;
}