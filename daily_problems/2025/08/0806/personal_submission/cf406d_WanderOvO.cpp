/*
每个位置的下一个位置如果能求出来，则建出了一棵树
每次询问 u 和 v 在哪里相遇，则只要求 anc = lca(u, v)
下面考虑如何快速建树
考虑第 i 个山的下一个山是谁
- 如果 i + 1 山的高度 >= i 山，则 i 能到的一定是不矮于自己的，i 能看到的所有山顶和 i 的顶连线，一定是斜率越来越大
  因此，能到的最右的山一定是斜率严格最大的，如何快速求是谁？
- 如果 i + 1 山的高度 < i 山，则后边既可以到更高的，也可以到更矮的，总体来说能到的也是斜率单调递增的
综上，我们需要维护一个和自己相连斜率单调递增的点列，取最后一个点
*/

LL n, x[N], y[N], m;
int fa[M][N], d[N], lg[N];
vector<vector<int>> e(N);

void dfs(int u, int f, int depth) {
    d[u] = depth;
    fa[0][u] = f;
    for (int i = 1; i <= lg[depth]; i++) {
        fa[i][u] = fa[i - 1][fa[i - 1][u]];
    }

    for (auto v : e[u]) {
        dfs(v, u, depth + 1);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) {
        swap(u, v);
    }

    while (d[u] > d[v]) {
        u = fa[lg[d[u] - d[v]]][u];
    }
    if (u == v) return u;

    for (int i = lg[d[u]]; i >= 0; i--) {
        if (fa[i][u] != fa[i][v]) {
            u = fa[i][u];
            v = fa[i][v];
        }
    }
    return fa[0][u];
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    
    vector<int> stk;
    stk.push_back(n);
    for (int i = n - 1; i > 0; i--) {
        while (stk.size() > 1) {
            int id1 = stk.back();
            stk.pop_back();
            int id2 = stk.back();
            stk.pop_back();

            if ( (y[id1] - y[i]) * (x[id2] - x[i]) < (y[id2] - y[i]) * (x[id1] - x[i]) ) {
                stk.push_back(id2);
            } else {
                stk.push_back(id2);
                stk.push_back(id1);
                break;
            }
        }

        e[stk.back()].push_back(i);
        stk.push_back(i);
    }

    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    dfs(n, 0, 1);

    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        int anc = lca(u, v);
        cout << anc << " ";
    }
}
