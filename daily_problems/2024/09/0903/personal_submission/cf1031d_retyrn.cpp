int n, k;

void solve() {
    cin >> n >> k;
    vector<string> g(n);
    cin >> g;
    vector<vector<int>> f(n, vector<int>(n, inf)); // 走到这里经过几个非a的字符
    f[0][0] = (g[0][0] != 'a');
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i - 1 >= 0) chmin(f[i][j], f[i-1][j] + (g[i][j] != 'a'));
            if (j - 1 >= 0) chmin(f[i][j], f[i][j-1] + (g[i][j] != 'a'));
        }
    }
    
    if (f[n-1][n-1] <= k) {
        cout << string(n * 2 - 1, 'a') << endl;
        return;
    }
    
    int mx = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (f[i][j] == k) {
                chmax(mx, i + j + 1);
            }
        }
    }
    string res(mx, 'a');
    
    vector<pii> q;
    for (int i = max(0, mx - n); i < n and mx - 1 - i >= 0; i ++) {
        int j = mx - 1 - i;
        if (f[i][j] == k) q.emplace_back(i, j);
    }
    
    if (em(q)) {
        q.emplace_back(0, 0);
        res += g[0][0];
    }
    
    while (sz(res) < n * 2 - 1) {
        vector<pii> nxt;
        char c = 'z';
        for (auto& [x, y] : q) {
            if (x + 1 < n) chmin(c, g[x + 1][y]);
            if (y + 1 < n) chmin(c, g[x][y + 1]);
        }
        res += c;
        for (auto& [x, y] : q) {
            if (x + 1 < n and g[x + 1][y] == c) nxt.emplace_back(x + 1, y);
            if (y + 1 < n and g[x][y + 1] == c) nxt.emplace_back(x, y + 1);
        }
        sort(all(nxt));
        complete_unique(nxt);
        q = move(nxt);
    }
    cout << res << endl;
}