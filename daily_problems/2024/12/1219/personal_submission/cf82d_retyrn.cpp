int n;

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    // 一定是一个数 加上一段区间
    vector<vector<int>> f(n + 1, vector<int>(n + 2, inf));
    vector<vector<int>> st(n + 1, vector<int>(n + 2, false));
    vector<vector<pii>> to(n + 1, vector<pii>(n + 2, {-1, -1}));
    vector<vector<pii>> get(n + 1, vector<pii>(n + 2, {-1, -1}));
    
    // f[i][j] 前面i位置 + [j, n]的段 的答案
    
    auto dfs = [&](auto&& self, int u, int l) -> int {
        if (st[u][l]) return f[u][l];
        if (l > n) {
            if (u == 0) {
                return 0;
            }
            get[u][l] = {u, -1};
            return a[u];
        }
        if (l == n) {
            if (u == 0) {
                get[u][l] = {n, -1};
                return a[n];
            }
            get[u][l] = {u, n};
            return max(a[n], a[u]);
        }
        if (u == 0 and l == n - 1) {
            get[u][l] = {n - 1, n};
            return max(a[n - 1], a[n]);
        }
        st[u][l] = true;
        
        if (u > 0) {
            // u + l
            int cur = self(self, 0, l + 1) + max(a[u], a[l]);
            if (chmin(f[u][l], cur)) {
                to[u][l] = {0, l + 1};
                get[u][l] = {u, l};
            }
            
            // u l+1
            cur = self(self, l, l + 2) + max(a[u], a[l+1]);
            if (chmin(f[u][l], cur)) {
                to[u][l] = {l, l + 2};
                get[u][l] = {u, l+1};
            }
            
            // l l+1
            cur = self(self, u, l + 2) + max(a[l], a[l+1]);
            if (chmin(f[u][l], cur)) {
                to[u][l] = {u, l + 2};
                get[u][l] = {l, l+1};
            }
        }
        else {
            // l l+1
            int cur = self(self, 0, l + 2) + max(a[l], a[l+1]);
            if (chmin(f[u][l], cur)) {
                to[u][l] = {0, l + 2};
                get[u][l] = {l, l+1};
            }
            
            // l l+2
            cur = self(self, l+1, l + 3) + max(a[l], a[l+2]);
            if (chmin(f[u][l], cur)) {
                to[u][l] = {l+1, l+3};
                get[u][l] = {l, l+2};
            }
            
            // l+1 l+2
            cur = self(self, l, l + 3) + max(a[l+1], a[l+2]);
            if (chmin(f[u][l], cur)) {
                to[u][l] = {l, l+3};
                get[u][l] = {l+1, l+2};
            }
        }
        return f[u][l];
    };
    
    int res = dfs(dfs, 0, 1);
    cout << res << endl;
    pii cur = {0, 1};
    
    while (cur.fi >= 0) {
        int x = cur.fi, y = cur.se;
        cout << get[x][y].fi;
        if (get[x][y].se >= 0) cout << ' ' << get[x][y].se << endl;
        else cout << endl;
        cur = to[x][y];
    }
}