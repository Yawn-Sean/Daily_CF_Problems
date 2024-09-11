int n;
int f[maxn][14][2];

vector<int> ask(vector<int>& a) {
    cout << sz(a) << endl;
    cout << a << endl;
    cout.flush();
    vector<int> res(n);
    cin >> res;
    return res;
}

void solve() {
    cin >> n;
    int m = std::__lg(n);
    vector<vector<vector<int>>> need(2, vector<vector<int>>(m + 1));
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            int u = (i >> j & 1);
            need[u][j].push_back(i);
        }
    }
    
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j <= m; j ++) {
            auto v = ask(need[i][j]);
            for (int t = 0; t < n; t ++) {
                f[t + 1][j][i] = v[t];
            }
        }
    }
    
    cout << -1 << endl;
    vector<int> res;
    for (int i = 1; i <= n; i ++) {
        int ans = inf;
        for (int j = 0; j <= m; j ++) {
            int u = (i >> j & 1);
            chmin(ans, f[i][j][u^1]);
        }
        res.push_back(ans);
    }
    cout << res << endl;
    cout.flush();
}