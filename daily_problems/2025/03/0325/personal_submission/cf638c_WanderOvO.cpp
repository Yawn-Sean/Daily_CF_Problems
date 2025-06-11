/*
删除次数应该是最大的度数
dfs 这颗树，当前在 u
先钦定删 u 的第一个孩子 v1，假设当前是时间 t，则 v1 到其孩子们的边需要至少从 t + 1 才能删除了
第二次删除 v2，则需要 t + 1 的时间有一个空拍
传递参数 stop，代表在时间戳为 stop 时需要空 1 次
*/

int n, k;
vector<vector<PII>> e(N);
vector<vector<int>> res(N);

void dfs(int u, int fa, int stop) {
    int cur = 0;
    for (auto edge : e[u]) {
        int v = edge.x, id = edge.y;
        if (v != fa) {
            cur++;
            if (cur == stop) {
                cur++;
            }
            res[cur].push_back(id);
            dfs(v, u, cur);
            k = max(k, cur);
        }
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }

    dfs(1, 0, 0);

    cout << k << "\n";
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        cout << res[i].size() << " ";
        sum += res[i].size();
        for (auto id : res[i]) {
            cout << id << " ";
        }
        cout << "\n";
    }
    assert(sum == n - 1);
}
