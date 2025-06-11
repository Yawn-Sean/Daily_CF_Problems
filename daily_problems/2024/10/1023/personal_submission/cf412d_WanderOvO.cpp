/*
先建立有向图
a 欠 b 的钱，连有向边 a -> b
则要么先 a，再别人，再 b，要么先 b 后 a
假如整个图是有向无环的，则反图拓扑序就是符合题意的
假如有环，缩点之后好像也不好搞，因为强连通分量不一定是环
但是似乎正图上按照 dfs 的顺序反向询问就是对的
*/

vector<int> e[N];
int n, m;
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    cout << u << " ";
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}    
