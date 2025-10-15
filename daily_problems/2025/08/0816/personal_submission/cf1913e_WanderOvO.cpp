/*
什么情况下不能满足条件？比如所有 a[i] 都是 m，但是所有 b[j] 都是 0，这必不可能发生
如何用数学式子描述这种情况？
(i, j) 有一个 1，则会同时贡献给 a[i] 和 b[j]
因此一个基本的约束就是 sum(a) = sum(b)
除此之外还有别的约束吗？

接下来，考虑如何最小化操作次数
首先可以发现，每个位置至多改变一次，所以上限是 nm 次
严重怀疑需要上科技，用网络流之类的东西才能最小化
相当于 a[i] 和 b[j] 做匹配，i 和 j 匹配有一个代价
最后还要看匹配出来的总流量是否对了
*/

int n, m, grid[M][M], a[M], b[M];

void meibao() {
    cin >> n >> m;
    atcoder::mcf_graph<int, int> mcf(n + m + 3);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s1 += a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        s2 += b[i];
    }

    if (s1 != s2) {
        cout << "-1\n";
        return;
    }

    int src = n + m + 1, dst = n + m + 2;
    for (int i = 1; i <= n; i++) {
        mcf.add_edge(src, i, a[i], 0);
    }
    for (int i = 1; i <= m; i++) {
        mcf.add_edge(i + n, dst, b[i], 0);
    }

    int cnt = 0;

    // 边权要有 1 的偏移量
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 0) {
                mcf.add_edge(i, j + n, 1, 2);
            } else {
                mcf.add_edge(i, j + n, 1, 0);
                cnt++;
            }
        }
    }

    auto res = mcf.flow(src, dst);
    int tot_cost = res.y, tot_amount = res.x;
    if (tot_amount != s1) {
        cout << "-1\n";
        return;
    }
    tot_cost += cnt - s1;
    cout << tot_cost << "\n";
}
