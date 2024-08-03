int n, m;
bool e[510][510]; // 反图
bool st[510];
string res;

void dfs(int u, char c) {
    res[u - 1] = c;
    st[u] = true;
    for (int i = 1; i <= n; i ++) {
        if (i != u and e[u][i] and !st[i]) {
            dfs(i, 'c' + 'a' - c);
        }
    }
}

void solve() {
    cin >> n >> m;
    DSU dsu(n + 1);
    // 有一条边没有连, 一定一个是a一个是c
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            e[i][j] = e[j][i] = true;
        }
    }
    
    while (m --) {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = false;
    }
    
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            if (e[i][j]) dsu.merge(i, j);
        }
    }
    res.resize(n);
    
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (!st[i]) {
            if (dsu.size(i) == 1) {
                res[i-1] = 'b';
            }
            else {
                dfs(i, 'a');
                cnt ++;
            }
        }
    }
    if (cnt > 1) {
        cout << "No" << endl;
        return;
    }
    
    // check
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            if (e[i][j]) {
                if (res[i-1] == 'b' or res[j-1] == 'b' or res[i-1] == res[j-1]) {
                    cout << "No" << endl;
                    return;
                }
            }
            else {
                if (abs(res[i-1] - res[j-1]) == 2) {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
    cout << res << endl;
}