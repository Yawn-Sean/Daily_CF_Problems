/*
显然至多加 3 条边，还得是初始 1 条边都没有的情况下
但凡有 1 条初始边，至多加 2 条边就可以了
假如存在某个点的度数 >= 2，至多加 1 条边就可以了
假如原本就存在奇数环（不是二分图），则无需加边
我们重点讨论加 1 条和加 2 条边的情况怎么计数，这里讨论的图一定是二分图
首先看一下，存在某个点度数 >= 2 是否是只加一条边的充要条件
充分性显然
必要性的话，反证法，假如所有点度数 < 2，则说明图是由若干孤立点 + 若干两个连起来的点组成，连 1 条边必然不行
所以，假设所有点的度数都 < 2，则要连 2 条边，其实就是选一对已经连接的点，再选一个孤立点或者一对点中的某个
假设有 cnt 对已经连接的点，则方案数有 cnt * (n - 2)
加 1 条边的情况怎么统计？
由于只能加一条边，所以只能连接同一个连通分支里面的点
怎么连？要构成奇数环的话，需要选颜色相同的点连起来，所以就是 0 点选 2 个或者 1 点选 2 个
*/

int T;
LL n, m;
vector<vector<int>> e(N);
vector<LL> d(N);
vector<int> color(N);
vector<bool> vis(N, false);
bool odd_loop;
LL cnt[2];

void dfs(int u, int c) {
    color[u] = c;
    for (auto &v : e[u]) {
        if (color[v] == -1) {
            dfs(v, c ^ 1);
        } else {
            if (c == color[v]) {
                odd_loop = true;
            }
        }
    }
}

void calc(int u) {
    cnt[color[u]]++;
    vis[u] = true;
    for (auto &v : e[u]) {
        if (!vis[v]) {
            calc(v);
        }
    }
}

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        d[u]++;
        d[v]++;
    }
    odd_loop = false;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            dfs(i, 0);
        }
    }

    if (odd_loop) {
        cout << "0 1\n";
        return;
    }

    if (m == 0) {
        cout << "3 " << n * (n - 1) * (n - 2) / 6 << "\n";
        return;
    }


    bool has_degree2 = false;
    for (int i = 1; i <= n; i++) {
        if (d[i] >= 2) {
            has_degree2 = true;
        }
    }

    if (has_degree2) {
        // 加 1 条边
        LL res = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cnt[0] = 0;
                cnt[1] = 0;
                calc(i);
                res += cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
            }
        }
        cout << "1 " << res << "\n";
    } else {
        // 加 2 条边
        cout << "2 " << m * (n - 2) << "\n";
    }
}                                                                                                              
