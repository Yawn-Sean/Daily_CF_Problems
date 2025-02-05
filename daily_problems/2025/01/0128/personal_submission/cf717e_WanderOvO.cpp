/*
如果一个点是 -1，则需要走到这个点奇数次才行
考虑从 1 开始走，遇到为 -1 的点之后直接原路返回到 1，则这个点变成 1 了
倘若 1 是 1，且有偶数个点是 -1，则一直这样搞就可以了
倘若 1 是 1，但是只有奇数个点是，那么最后走回来之后只要再多走 3 步就好了
倘若 1 是 -1，也是类似的做法
不过输出要求 <= 1e7 的长度，所以不能一直这么搞，这种策略只适合 3e3 以内的情况
n >= 2 且不考虑输出长度的情况下，似乎不存在无解的情况
能否几乎一次遍历完成？可以的
直接遍历，假如某个子树的根结点走到之后颜色不对，就用其上面的父亲结点调整一下
如果 1 为根的子树不行，但是所有其他子树都行了，就按照上面提到的 3 步走方法就好了
*/ 

int n, a[N];
vector<vector<int>> e(N);
vector<int> res;

void dfs(int u, int fa) {
    res.push_back(u);
    if (u != 1) {
        a[u] = 1 - a[u];
    }
    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u);
            res.push_back(u);
            a[u] = 1 - a[u];
        }
    }
    if (a[u] != 1 && u != 1) {
        res.push_back(fa);
        a[fa] = 1 - a[fa];
        res.push_back(u);
        a[u] = 1 - a[u];
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            a[i] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    if (a[1] == 0) {
        a[1] = 1;
        for (auto v : e[1]) {
            res.push_back(v);
            res.push_back(1);
            res.push_back(v);
            break;
        }
    }
    for (auto v : res) {
        cout << v << " ";
    }
}
