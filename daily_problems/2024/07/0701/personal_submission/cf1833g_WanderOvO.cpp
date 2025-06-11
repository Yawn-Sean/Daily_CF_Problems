/*
自底向上，满 3 删除即可
*/

int T;
vector<PII> e[N];
int sz[N], n;
vector<int> res;
bool ok;

void dfs(int u, int fa) {
    sz[u] = 1;
    bool is_leaf = true;
    for (auto &edge : e[u]) {
        int v = edge.x, id = edge.y;
        if (v != fa) {
            is_leaf = false;
            dfs(v, u);
            if (sz[v] == 3) {
                res.pb(id);
            } else {
                if (sz[v] < 3) {
                    sz[u] += sz[v];
                } else {
                    ok = false;
                }
            }
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb({v, i});
        e[v].pb({u, i});
    }
    ok = true;
    res.clear();
    dfs(1, 0);
    if (sz[1] != 3) {
        ok = false;
    }
    if (ok) {
        cout << res.size() << "\n";
        for (auto id : res) {
            cout << id << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}      