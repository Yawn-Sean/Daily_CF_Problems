int n, m, k;

int cal(vector<int>& aim, vector<int>& b, int u) {
    int res = 0;
    for (int i = 0; i < sz(aim); i ++) {
        res += (aim[i] != (b[i] ^ u));
    }
    return res;
}
void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int>(m));
    cin >> g;
    int res = inf;
    
    if (n > k) {
        // 一定有一行没有变
        for (int i = 0; i < n; i ++) {
            int cur = 0;
            for (int j = 0; j < n; j ++) {
                cur += min(cal(g[i], g[j], 0), cal(g[i], g[j], 1));
            }
            chmin(res, cur);
        }
    }
    else {
        vector<vector<int>> g1(m, vector<int>(n));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                g1[i][j] = g[j][i];
            }
        }
        vector<int> aim(n);
        for (int st = 0; st < (1 << n); st ++) {
            for (int i = 0; i < n; i ++) {
                aim[i] = (st >> i & 1);
            }
            int cur = 0;
            for (int i = 0; i < m; i ++) {
                cur += min(cal(aim, g1[i], 0), cal(aim, g1[i], 1));
            }
            chmin(res, cur);
        }
    }
    cout << (res <= k ? res : -1) << endl;
}