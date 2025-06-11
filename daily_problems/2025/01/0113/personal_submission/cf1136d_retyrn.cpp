int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    
    vector<int> st(n + 1, false);
    int res = 0, siz = 1;
    st[a[n-1]] = true;
    
    for (int i = n - 2; i >= 0; i --) {
        int who = a[i];
        int cur = 0;
        for (auto x : g[who]) {
            cur += st[x];
        }
        
        if (siz == cur) res += 1;
        else {
            siz += 1;
            st[who] = true;
        }
    }
    cout << res << endl;
}