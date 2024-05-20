int n, m;

void solve() {
    // 保持矩阵扁平
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    cin >> g;
    if (n > m) {
        vector<vector<int>> nxt(m, vector<int>(n));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                nxt[i][j] = g[j][i];
            }
        }
        g = move(nxt);
        swap(n, m);
    }
    
    // n <= m
    
    // 计算每行每列的和
    vector<ll> row(n), col(m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            row[i] += g[i][j];
            col[j] += g[i][j];
        }
    }
    
    if (n <= 4) {
        ll res = accumulate(all(row), 0ll);
        cout << res << endl;
        return;
    }
    
    ll res = 0;
    
    // 四个行
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    
    auto init = [&]() {
        sum = 0;
        while (!em(q)) q.pop();
    };
    
    for (int i = 0; i < n; i ++) {
        sum += row[i];
        q.push(row[i]);
        while (sz(q) > 4) {
            sum -= q.top();
            q.pop();
        }
        res = max(res, sum);
    }
    
    // 四个列
    init();
    for (int i = 0; i < m; i ++) {
        sum += col[i];
        q.push(col[i]);
        while (sz(q) > 4) {
            sum -= q.top();
            q.pop();
        }
        res = max(res, sum);
    }
    
    // 一行三列 枚举选哪一行
    for (int i = 0; i < n; i ++) {
        init();
        for (int j = 0; j < m; j ++) {
            sum += col[j] - g[i][j];
            q.push(col[j] - g[i][j]);
            while (sz(q) > 3) {
                sum -= q.top();
                q.pop();
            }
            res = max(res, sum + row[i]);
        }
    }
    
    // 三行一列 枚举是哪一列
    for (int j = 0; j < m; j ++) {
        init();
        for (int i = 0; i < n; i ++) {
            sum += row[i] - g[i][j];
            q.push(row[i] - g[i][j]);
            while (sz(q) > 3) {
                sum -= q.top();
                q.pop();
            }
            res = max(res, sum + col[j]);
        }
    }
    
    // 2行2列 枚举哪两行
    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = i1 + 1; i2 < n; i2 ++) {
            init();
            for (int j = 0; j < m; j ++) {
                sum += col[j] - g[i1][j] - g[i2][j];
                q.push(col[j] - g[i1][j] - g[i2][j]);
                while (sz(q) > 2) {
                    sum -= q.top();
                    q.pop();
                }
                res = max(res, sum + row[i1] + row[i2]);
            }
        }
    }
    
    cout << res << endl;
}