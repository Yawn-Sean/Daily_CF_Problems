/*
相当于每个点都只有一条入边，可能自环，所以是外向基环森林
先看看有几个外向基环树，找出来
假设有 cnt 个外向基环树，则至少需要改动 cnt - 1 条边，也可能是改动 cnt 条边
假如有一个外向基环树，其环是自环，则其他的基环树选一个环上的点连过来即可
假设所有外向基环树的环都不是自环，则选一个的环改成自环，其他的选一个环上的点连过来
*/

vector<vector<int>> e(N);
int p[N], n, d[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        // 建内向基环树
        e[i].push_back(p[i]);
        d[p[i]]++;
    }
    // 环上的点的入度 != 0，非环上的 = 0
    toposort();
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        e[p[i]].push_back(i);
    }
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && d[i] != 0) {
            roots.push_back(i);
            dfs(i);
        }
    }
    int self_loop_root = 0;
    for (auto v : roots) {
        if (p[v] == v) {
            self_loop_root = v;
            break;
        }
    }
    if (self_loop_root != 0) {
        cout << roots.size() - 1 << "\n";
        for (auto v : roots) {
            if (v != self_loop_root) {
                p[v] = self_loop_root;
            }
        }
    } else {
        cout << roots.size() << "\n";
        int root = roots[0];
        p[root] = root;
        for (int i = 1; i < roots.size(); i++) {
            p[roots[i]] = root;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
}
