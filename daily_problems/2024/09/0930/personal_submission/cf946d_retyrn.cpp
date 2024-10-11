int n, m, k;
int f[510][510];
int g[510];

void solve() {
    cin >> n >> m >> k;
    mem(f, 0x3f);
    f[0][0] = 0;
    
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        vector<int> v;
        mem(g, 0x3f);
        for (int j = 0; j < m; j ++) {
            if (s[j] == '1') {
                for (int t = 0; t < sz(v); t ++) {
                    int lesson = sz(v) + 1 - t, cost = j - v[t] + 1;
                    chmin(g[lesson], cost);
                }
                v.push_back(j);
            }
        }
        chmin(g[0], 0);
        chmin(g[1], 1);
        int cnt = sz(v);
        
        for (int j = 0; j <= k; j ++) {
            for (int t = 0; t <= cnt and t <= j; t ++) {
                int lesson = cnt - t;
                chmin(f[i][j], f[i-1][j-t] + g[lesson]);
            }
        }
    }
    
    int res = inf;
    for (int i = 0; i <= k; i ++) {
        chmin(res, f[n][i]);
    }
    cout << res << endl;
}