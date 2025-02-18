/*
完全图有 C(n, 3) 个三元环，不超过 1e18
只计算 bob 的三元环，怎么做？由于最好是 m sqrt(m) 的做法，也会超时，所以应该不是直接求
对于一个三元环，要么在原图中，要么在补图中，要么都不在
什么时候都不在？假如一个三元环的一条边在原图中，一条边在补图中，则都不在
考虑如何计数这样的情况有多少个
枚举 bob 的一条边 (u, v)，枚举 w，看 (u, w) 和 (v, w) 是否都在 bob 这边，不都在则两个图总的三元环个数 - 1，O(m^2)
枚举 bob 中的点 u，度数为 d[u]，即 bob 的图中 u 有 d[u] 个邻点，所以有 n - 1 - d[u] 个点在 alice 那边
只要取 u，u 在 bob 中的邻点，u 在 alice 中的邻点，则就是失去的三元环方案数
*/

LL n, m, d[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    LL res = n * (n - 1) * (n - 2) / 6;
    LL disappear = 0;
    for (int i = 1; i <= n; i++) {
        disappear += d[i] * (n - 1 - d[i]);
    }
    disappear /= 2;
    res -= disappear;
    cout << res << "\n";
}
