/*
预处理 dfs 序，维护每个子树对应 dfs 序中的左右区间端点
*/

int n, q, l[N], r[N], idx;
vector<int> dfs_order;
vector<vector<int>> e(N);

void dfs(int u) {
    dfs_order.push_back(u);
    l[u] = idx;
    for (auto v : e[u]) {
        idx++;
        dfs(v);
    }
    r[u] = idx;
}

void meibao() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        e[p].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
    }
    dfs(1);
    while (q--) {
        int u, k;
        cin >> u >> k;
        if (r[u] - l[u] + 1 < k) {
            cout << "-1\n";
        } else {
            cout << dfs_order[l[u] + k - 1] << "\n";
        }
    }
}
