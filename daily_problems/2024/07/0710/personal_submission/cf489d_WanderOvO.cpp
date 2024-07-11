/*
枚举头和尾的两个点 u, v
假设 u 能到的点集合为 s[u]，能到 v 的点的集合为 rs[v]，则求 s[u] & rs[v]
使用 bitset 也过不了
*/

int T;  
int n, m;
vector<vector<int>> e(N);
bool adj[N][N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        adj[u][v] = true;
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            LL cnt = 0;
            for (auto &v : e[i]) {
                if (adj[v][j]) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                res += (cnt * (cnt - 1)) / 2;
            }
        }
    }
    cout << res << "\n";
}