using ai3 = array<int, 3>;
int dp[maxn][200];
pii from[maxn][200];
int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<int> id(n);
    iota(all(id), 0);
    
    sort(all(id), [&](int x, int y) {
        return a[x] < a[y];
    });
    
    vector<vector<ai3>> task(n);
    
    for (int i = 1; i <= m; i ++) {
        int e, p, time;
        cin >> e >> time >> p;
        e --;
        task[e].push_back({p, time, i});
    }
    
    int last = 0;
    vector<int> path;
    
    for (auto idx : id) {
        int len = sz(task[idx]);
        for (int i = 0; i <= len; i ++) {
            for (int j = 0; j < 200; j ++) {
                dp[i][j] = inf;
                from[i][j].fi = 0, from[i][j].se = 0;
            }
        }
        
        dp[0][0] = 0;
        from[0][0] = mpr(-1, -1);
        int mn = inf, x = -1, y = -1;
        for (int i = 1; i <= len; i ++) {
            int p = task[idx][i-1][0], time = task[idx][i-1][1];
            for (int j = 199; j >= 0; j --) {
                dp[i][j] = dp[i-1][j];
                from[i][j] = from[i-1][j];
                
                if (j >= p and chmin(dp[i][j], dp[i-1][j-p] + time)) {
                    from[i][j] = mpr(i-1, j-p);
                }
                
                if (j >= 100 and chmin(mn, dp[i][j])) {
                    x = i, y = j;
                }
            }
        }
        
        if (mn + last > a[idx]) {
            cout << -1 << endl;
            return;
        }
        
        vector<int> path1;
        while (x > 0) {
            int nx = from[x][y].fi, ny = from[x][y].se;
            if (nx < 0 or ny < 0) break;
            int number = task[idx][nx][2], time = task[idx][nx][1];
            if (dp[nx][ny] + time == dp[x][y]) {
                path1.push_back(number);
            }
            x = nx, y = ny;
        }
        
        reverse(all(path1));
        for (auto t : path1) {
            path.pbk(t);
        }
        
        last += mn;
    }
    
    cout << sz(path) << endl;
    cout << path << endl;
}