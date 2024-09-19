int n;
int cnt[maxn];

void solve() {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i ++) {
        int len;
        cin >> len;
        g[i].resize(len);
        cin >> g[i];
        for (auto x : g[i]) {
            cnt[x] += 1;
        }
    }
    
    Z res = 0;
    for (int i = 0; i < n; i ++) {
        int t = sz(g[i]);
        for (auto x : g[i]) {
            res += Z(1) / t * cnt[x];
        }
    }
    res /= n;
    res /= n;
    
    cout << res << endl;
}