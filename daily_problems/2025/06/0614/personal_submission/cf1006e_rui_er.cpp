const int N = 2e5 + 5;

int n, m, fa[N], dfn[N], vtx[N], sz[N], tms;
vector<int> e[N];

void dfs(int u) {
    dfn[u] = ++tms;
    vtx[tms] = u;
    sz[u] = 1;
    for(int v: e[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 2, n) cin >> fa[i];
    rep(i, 2, n) e[fa[i]].push_back(i);
    dfs(1);
    while(m--) {
        int u, k;
        cin >> u >> k;
        if(k > sz[u]) cout << -1 << endl;
        else cout << vtx[dfn[u] + k - 1] << endl;
    }
    return 0;
}
