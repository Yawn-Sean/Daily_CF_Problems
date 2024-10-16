/*
两个子树不能有交叉，所以不能选有父子关系的结点
假如整个树是一条链，则不可能选出两个不交叉的子树
预处理所有的子树和，然后再预处理以 u 为根的子树中所有子树中的最大值，设为 mx[u]
则 mx[u] = max(mx[u], mx[v])
再算只从以 u 为根的子树中选两个不交叉子树，和最大是多少，设为 max_sum[u]
max_sum[u] = max(max_sum[u], max_sum[v])
max_sum[u] = max(max_sum[u], 两个最大的 mx[v] 的和)
*/

LL n, a[N], sum[N], mx[N], max_sum[N];
vector<vector<int>> e(N);

void get_sum(int u, int fa) {
    sum[u] = a[u];
    for (auto v : e[u]) {
        if (v != fa) {
            get_sum(v, u);
            sum[u] += sum[v];
        }
    }
}

void get_mx(int u, int fa) {
    mx[u] = sum[u];
    for (auto v : e[u]) {
        if (v != fa) {
            get_mx(v, u);
            mx[u] = max(mx[u], mx[v]);
        }
    }
}

void get_max_sum(int u, int fa) {
    max_sum[u] = -INFLL;
    vector<LL> mxs;
    for (auto v : e[u]) {
        if (v != fa) {
            mxs.pb(mx[v]);
            get_max_sum(v, u);
            max_sum[u] = max(max_sum[u], max_sum[v]);
        }
    }
    sort(mxs.begin(), mxs.end());
    if (mxs.size() >= 2) {
        int cnt = mxs.size();
        max_sum[u] = max(max_sum[u], mxs[cnt - 1] + mxs[cnt - 2]);
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    get_sum(1, 0);
    get_mx(1, 0);
    get_max_sum(1, 0);
    LL res = -INFLL;
    for (int i = 1; i <= n; i++) {
        res = max(res, max_sum[i]);
    }
    if (res < -INFLL / 2) {
        cout << "Impossible\n";
    } else {
        cout << res << "\n";
    }
}  
