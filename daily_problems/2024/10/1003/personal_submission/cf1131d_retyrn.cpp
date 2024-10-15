int n, m;

void solve() {
    // 所有的等于号 缩点成一个点
    // 之后不可以存在环 要求有拓扑序
    cin >> n >> m; // [0, n-1] [n, n+m-1]
    vector<string> g(n);
    cin >> g;
    
    int con = n + m;
    DSU dsu(n + m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == '=') {
                con -= dsu.merge(i, n + j);
            }
        }
    }
    vector<vector<int>> c(n + m);
    vector<int> d(n + m);
    for (int i = 0; i < n; i ++) {
        int root = dsu.leader(i);
        c[root].push_back(i);
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == '<') {
                d[dsu.leader(n + j)] += 1;
            }
            else if (g[i][j] == '>') {
                d[root] += 1;
            }
            if (g[i][j] != '=' and dsu.same(i, n + j)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    for (int i = 0; i < m; i ++) {
        int root = dsu.leader(n + i);
        c[root].push_back(n + i);
        for (int j = 0; j < n; j ++) {
            if (g[j][i] == '<') {
                d[root] += 1;
            }
            else if (g[j][i] == '>') {
                d[dsu.leader(j)] += 1;
            }
        }
    }
    
    for (auto& x : d) {
        if (x & 1) {
            cout << "No" << endl;
            return;
        }
        x >>= 1;
    }
    
    queue<int> q;
    vector<int> res(n + m, -1);
    for (int i = 0; i < n + m; i ++) {
        if (dsu.leader(i) != i) continue;
        if (d[i] == 0) {
            q.push(i);
            res[i] = 1;
        }
    }
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        int rank = res[t];
        for (auto x : c[t]) {
            if (x < n) {
                for (int j = 0; j < m; j ++) {
                    if (g[x][j] == '<') {
                        int nr = dsu.leader(n + j);
                        if (-- d[nr] == 0) {
                            res[nr] = rank + 1;
                            q.push(nr);
                        }
                    }
                }
            }
            else {
                for (int i = 0; i < n; i ++) {
                    if (g[i][x - n] == '>') {
                        int nr = dsu.leader(i);
                        if (-- d[nr] == 0) {
                            res[nr] = rank + 1;
                            q.push(nr);
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n + m; i ++) {
        if (dsu.leader(i) != i) res[i] = res[dsu.leader(i)];
        if (res[i] == -1) {
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;
    for (int i = 0; i < n; i ++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    for (int i = n; i < n + m; i ++) {
        cout << res[i] << ' ';
    }
    
}