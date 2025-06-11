int n, m;

void solve() {
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n, inf));
    
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j ++) {
            if (s[j] == '1') d[i][j] = 1;
        }
        d[i][i] = 0;
    }
    
    for (int k = 0; k < n; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i ++) {
        cin >> p[i];
        p[i] --;
    }
    vector<int> res{p[0] + 1};
    
    int j = 0;
    while (j < m - 1) {
        int cur = j;
        while (cur < m - 1 and d[p[j]][p[cur+1]] == d[p[j]][p[cur]] + 1) cur ++;
        res.pbk(p[cur] + 1);
        j = cur;
    }
    
    cout << sz(res) << endl;
    cout << res << endl;
}