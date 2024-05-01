/*
点总数比较少，考虑枚举 u 点，dfs 到回来之后，再看 u 能不能有恰好两个非环上邻接点
*/

int T;
int n, m, e[N][N], d[N], tmpd[N];
int vis[N];
bool s[N];
stack<int> stk;
vector<int> edges[N];
bool ok = false;

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = 0;
        }
        d[i] = 0;
        edges[i].clear();
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u][v] = 1;
        e[v][u] = 1;
        edges[u].pb(v);
        edges[v].pb(u);
        d[u]++;
        d[v]++;
    }
    
    ok = false;
    for (int i = 1; i <= n && !ok; i++) {
        for (int j = 1; j <= n; j++) {
            vis[j] = false;
            s[j] = false;
            tmpd[j] = d[j];
        }
        while (!stk.empty()) {
            stk.pop();
        }
        if (d[i] >= 4) {
            dfs(i, 0, i);
        }
        if (ok) {
            // cout << i << "\n";
            cout << "YES\n";
            vector<int> nodes;
            while (!stk.empty()) {
                int u = stk.top();
                stk.pop();
                nodes.pb(u);
            }
            cout << nodes.size() + 2 << "\n";
            for (int j = 0; j < nodes.size(); j++) {
                if (j != nodes.size() - 1) {
                    cout << nodes[j] << " " << nodes[j + 1] << "\n";
                } else {
                    cout << nodes[0] << " " << nodes.back() << "\n";
                }
            }
            int cnt = 0;
            for (int j = 1; j <= n && cnt < 2; j++) {
                if (e[i][j] == 1 && !s[j]) {
                    cnt++;
                    cout << i << " " << j << "\n";
                }
            }
            return;
        }
    }
    if (!ok) {
        cout << "NO\n";
    }
}         