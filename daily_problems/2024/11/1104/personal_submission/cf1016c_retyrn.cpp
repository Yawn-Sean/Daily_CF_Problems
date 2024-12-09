int n;

void solve() {
    cin >> n;
    vector<vector<ll>> g(2, vector<ll>(n));
    cin >> g;
    
    vector<vector<ll>> s(2, vector<ll>(n + 1));
    for (int i = 0; i < 2; i ++) {
        for (int j = 1; j <= n; j ++) {
            s[i][j] = s[i][j-1] + g[i][j-1];
        }
    }
    
    auto query = [&](int l, int r) -> ll {
        if (l > r) return 0LL;
        return s[0][r + 1] - s[0][l] + s[1][r + 1] - s[1][l];
    };
    
    // 0
    // --->
    // <---
    vector<ll> s0(n + 1, 0);
    for (int i = n - 1; i >= 0; i --) {
        s0[i] = s0[i+1] + query(i+1, n-1);
        s0[i] += g[1][i] * ((n - i) * 2 - 1);
    }
    // 1
    // <---
    // --->
    vector<ll> s1(n + 1, 0);
    for (int i = n - 1; i >= 0; i --) {
        s1[i] = s1[i+1] + query(i+1, n-1);
        s1[i] += g[0][i] * ((n - i) * 2 - 1);
    }
    
    ll res = 0;
    vector<vector<int>> st(2, vector<int>(n, false));
    
    // 枚举第二段开始所在的位置
    ll cur = 0, t = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n * 2; i ++) {
        if (x == 0 and !st[1][y]) {
            chmax(res, cur + s0[y] + t * query(y, n - 1));
        }
        if (x == 1 and !st[0][y]) {
            chmax(res, cur + s1[y] + t * query(y, n - 1));
        }
        st[x][y] = true;
        cur += g[x][y] * (t ++);
        
        if (x == 0) {
            if (!st[1][y]) x += 1;
            else y += 1;
        }
        else {
            if (!st[0][y]) x -= 1;
            else y += 1;
        }
    }
    
    chmax(res, cur);
    cout << res << endl;
}