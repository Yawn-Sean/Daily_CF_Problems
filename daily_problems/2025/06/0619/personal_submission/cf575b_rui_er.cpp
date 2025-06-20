const int N = 1e5 + 5, M = 1e6 + 5, mod = 1e9 + 7;
typedef Modint<mod> mint;

int n, k, dep[N], fa[17][N], s[M], cntU[N], cntD[N];
mint pw2[M];
vector<tuple<int, int>> e[N];

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[0][u] = f;
    rep(i, 1, 16) fa[i][u] = fa[i - 1][fa[i - 1][u]];
    for(auto [v, w]: e[u]) if(v != f) dfs1(v, u);
}

int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    per(i, 16, 0) if(dep[fa[i][u]] >= dep[v]) u = fa[i][u];
    if(u == v) return u;
    per(i, 16, 0) if(fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}

void dfs2(int u, int f) {
    for(auto [v, w]: e[u]) {
        if(v != f) {
            dfs2(v, u);
            cntU[u] += cntU[v];
            cntD[u] += cntD[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, 0);
        e[v].emplace_back(u, w);
    }
    dfs1(1, 0);
    cin >> k;
    pw2[0] = 1;
    rep(i, 1, k) pw2[i] = pw2[i - 1] * 2;
    s[0] = 1;
    rep(i, 1, k) {
        cin >> s[i];
        int u = s[i - 1], v = s[i], p = LCA(u, v);
        ++cntU[u]; --cntU[p];
        ++cntD[v]; --cntD[p];
    }
    dfs2(1, 0);
    mint ans = 0;
    rep(u, 1, n) {
        for(auto [v, w]: e[u]) {
            if(w) {
                if(dep[u] < dep[v]) ans += pw2[cntD[v]] - 1;
                else ans += pw2[cntU[u]] - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
