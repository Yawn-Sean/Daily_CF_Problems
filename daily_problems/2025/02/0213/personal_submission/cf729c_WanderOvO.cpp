/*
显然总耗油量是不变的
两个加油站 g[i] 和 g[i + 1] 之间，最保守就是用 g[i + 1] - g[i] 的油，走 2 * (g[i + 1] - g[i]) 分钟到
倘若油箱够大，这样走之后还有剩余油，则可以选择把一些公里换成加速模式
假设选第 i 辆车，价格 c[i]，油箱大小 v[i]
如果 v[i] < 最大的 g[j + 1] - g[j]，则到不了，不可选
如果 v[i] >= 最大的 g[j + 1] - g[j]，考虑怎么样能更快
对于某个 g[j + 1] - g[j]：
- 普通模式走完剩余油量为 v[i] - (g[j + 1] - g[j])
- 因此可以 min(v[i] - (g[j + 1] - g[j]), g[j + 1] - g[j]) 的距离用加速模式
- 把 g[j + 1] - g[j] 从小到大排个序，二分找一下第一个 >= v[i] - g[j + 1] + g[j] 的位置
- v[i] - (g[j + 1] - g[j]) <= g[j + 1] - g[j]
- v[i] <= 2 * (g[j + 1] - g[j])
*/

LL n, k, s, t, c[N], v[N], g[N], sum_g[N], d[N], maxd;

void meibao() {
    cin >> n >> k >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> v[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> g[i];
    }
    
    k++;
    g[k] = s;
    sort(g + 1, g + k + 1);
    for (int i = 1; i <= k; i++) {
        maxd = max(maxd, g[i] - g[i - 1]);
        d[i] = 2 * (g[i] - g[i - 1]);
    }
    sort(d + 1, d + k + 1);
    for (int i = 1; i <= k; i++) {
        sum_g[i] = sum_g[i - 1] + d[i] / 2;
    }

    LL res = INFLL;
    for (int i = 1; i <= n; i++) {
        if (v[i] >= maxd) {
            int pos = lower_bound(d + 1, d + k + 1, v[i]) - d - 1;
            // [1, pos] 都是 v[i] >= 2 * (g[j] - g[j - 1]) 的，可以全程加速
            LL min_t = 0;
            min_t += sum_g[pos];
            // [pos + 1, k] 需要分加速段和普通段算
            LL left_dist = sum_g[k] - sum_g[pos];
            LL boost_dist = v[i] * (k - pos) - left_dist;
            LL normal_dist = left_dist - boost_dist;
            normal_dist = max(normal_dist, 0LL);
            min_t += boost_dist + normal_dist * 2;
            if (min_t <= t)
                res = min(res, c[i]);
        }
    }
    if (res == INFLL) {
        res = -1;
    }
    cout << res << "\n";
}
