/*
分析一下 f 函数的性质
由于 max 的存在，所以 f 越多是越大的，因此我们会尽量去更远的地方
考虑以 1 为根，并求以 1 为起始点能得到的最大权值，则可以从 1 开始一直往下搞，一直到叶子，求叶子里面最大的
稍等一下，如果我们是先 dfs，再自底向上，则我们事实上可以求出所有的以 1 为结尾的路径的最大值
并且可以求出，在以 i 为根的子树中，以 i 结尾的路径的最大值
如果每个点还能再求来自上面的最大值，就做完这个题了
考虑 up[i] 为以 i 结尾，且从上面转移过来的最大值
好像往下的最大和次大以及转移的来源都得存一下，不然处理不了，类似树的直径的 DP 求法
up[1] = a[1]
up[v] = max(up[u], a[v]) + sqrt(min(up[u], a[v]))
*/

LL n, a[N], down[N][2], from[N][2], up[N];
vector<vector<int>> e(N);

void dfs_down(int u, int fa) {
    down[u][0] = a[u];
    for (auto v : e[u]) {
        if (v != fa) {
            dfs_down(v, u);
            LL t = sqrt(min(a[u], down[v][0]));
            LL c = max(a[u], down[v][0]) + t;
            if (c > down[u][0]) {
                down[u][1] = down[u][0];
                from[u][1] = from[u][0];
                down[u][0] = c;
                from[u][0] = v;
            } else if (c > down[u][1]) {
                down[u][1] = c;
                from[u][1] = v;
            }
        }
    }
}

void dfs_up(int u, int fa) {
    for (auto v : e[u]) {
        if (v != fa) {
            LL mx = 0;
            if (v == from[u][0]) {
                mx = max(up[u], down[u][1]);
            } else {
                mx = max(up[u], down[u][0]);
            }

            LL t = sqrt(min(a[v], mx));
            up[v] = max(a[v], mx) + t;

            dfs_up(v, u);
        }
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
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs_down(1, 0);
    up[1] = a[1];
    dfs_up(1, 0);

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res = max({res, down[i][0], up[i]});
    }
    cout << res << "\n";
}   
