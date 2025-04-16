/*
Alice 会不会需要折返呢？是不会的
Bob 需要看自己能逃跑到最深为多少的叶子
Bob 要么直接往下走到最深的叶子，要么往上走 cnt 步，到某个 u(x 要属于 u 子树)，Alice 往下走 cnt 步，至多走到 u 的父亲
然后 Bob 沿着 u 一直往下走，走到 u 子树最深的叶子里面去
*/

int n, x;
vector<vector<int>> e(N);
int d[N], l[N], r[N], timestamp = 0, deepest_leaf[N];

void dfs(int u, int fa, int depth) {
    timestamp++;
    d[u] = depth;
    l[u] = timestamp;
    bool is_leaf = true;
    for (auto v : e[u]) {
        if (v != fa) {
            is_leaf = false;
            dfs(v, u, depth + 1);
            deepest_leaf[u] = max(deepest_leaf[u], deepest_leaf[v]);
        }
    }
    timestamp++;
    r[u] = timestamp;
    if (is_leaf) {
        deepest_leaf[u] = depth;
    }
}

void meibao() {
    cin >> n >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0, 0);

    int res = 2 * deepest_leaf[x];
    for (int i = 1; i <= n; i++) {
        if (l[i] <= l[x] && r[x] <= r[i]) {
            if (d[x] - d[i] < d[i]) {
                res = max(res, deepest_leaf[i] * 2);
            }
        }
    }
    cout << res << "\n";
}   
