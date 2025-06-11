/*
从 s 和 t 出发分别求最短路
枚举不连通的两个点，然后看会不会改变最短路
*/

int T;
vector<vector<int>> e(N);
bool adj[N][N];
int n, m, s, t, d[2][N];

void bfs(int st, int d[]) {
    bool vis[N] = {false};
    queue<int> q;
    q.push(st);
    d[st] = 0;
    vis[st] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : e[u]) {
            if (!vis[v]) {
                vis[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve1() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        adj[u][v] = true;
        adj[v][u] = true;
    }
    
    bfs(s, d[0]);
    bfs(t, d[1]);
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!adj[i][j]) {
                int new_d = min(d[0][i] + d[1][j] + 1, d[0][j] + d[1][i] + 1);
                if (new_d >= d[0][t]) {
                    res++;
                }
            }
        }
    }
    cout << res;
}        