int n;

void solve() {
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> op(n + 1, -1);
    vector<int> val(n + 1, -1);
    
    // op: AND-0 OR-1 XOR-2 NOT-3 IN-4
    
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        if (s[0] == 'A') {
            op[i] = 0;
            int x, y;
            cin >> x >> y;
            g[i].push_back(x);
            g[i].push_back(y);
        }
        else if (s[0] == 'O') {
            op[i] = 1;
            int x, y;
            cin >> x >> y;
            g[i].push_back(x);
            g[i].push_back(y);
        }
        else if (s[0] == 'X') {
            op[i] = 2;
            int x, y;
            cin >> x >> y;
            g[i].push_back(x);
            g[i].push_back(y);
        }
        else if (s[0] == 'N') {
            op[i] = 3;
            int x;
            cin >> x;
            g[i].push_back(x);
        }
        else {
            op[i] = 4;
            int x;
            cin >> x;
            val[i] = x;
        }
    }
    
    function<int(int)> dfs = [&](int u) {
        if (val[u] != -1) return val[u];
        if (op[u] == 0) {
            int x = dfs(g[u][0]);
            int y = dfs(g[u][1]);
            return val[u] = (x & y);
        }
        
        if (op[u] == 1) {
            int x = dfs(g[u][0]);
            int y = dfs(g[u][1]);
            return val[u] = (x | y);
        }
        if (op[u] == 2) {
            int x = dfs(g[u][0]);
            int y = dfs(g[u][1]);
            return val[u] = (x ^ y);
        }
        return val[u] = dfs(g[u][0]) ^ 1;
    };
    
    dfs(1);
    
    // 找到可以改变根的值的所有点
    vector<bool> change(n + 1, false);
    change[1] = true;
    function<void(int)> dfs1 = [&](int u) {
        if (!change[u]) return;
        if (op[u] == 0) {
            int x = g[u][0], y = g[u][1];
            if (val[u] == 1) {
                change[x] = change[y] = true;
                dfs1(x);
                dfs1(y);
            }
            else {
                // 必须有0
                if (val[x] == 0 and val[y] == 0) return;
                if (val[x] == 0) {
                    change[x] = true;
                    dfs1(x);
                }
                if (val[y] == 0) {
                    change[y] = true;
                    dfs1(y);
                }
            }
        }
        else if (op[u] == 1) {
            int x = g[u][0], y = g[u][1];
            if (val[u] == 0) {
                change[x] = change[y] = true;
                dfs1(x);
                dfs1(y);
            }
            else {
                // 必须有1
                if (val[x] == 1 and val[y] == 1) return;
                if (val[x] == 1) {
                    change[x] = true;
                    dfs1(x);
                }
                if (val[y] == 1) {
                    change[y] = true;
                    dfs1(y);
                }
            }
        }
        else if (op[u] == 2) {
            int x = g[u][0], y = g[u][1];
            change[x] = change[y] = true;
            dfs1(x);
            dfs1(y);
        }
        else if (op[u] == 3) {
            int x = g[u][0];
            change[x] = true;
            dfs1(x);
        }
    };
    dfs1(1);
    
    string res;
    int ans = val[1];
    
    for (int i = 1; i <= n; i ++) {
        if (op[i] == 4) {
            if (change[i]) res.pbk('0' + (1 ^ ans));
            else res.pbk('0' + ans);
        }
    }
    cout << res << endl;
}