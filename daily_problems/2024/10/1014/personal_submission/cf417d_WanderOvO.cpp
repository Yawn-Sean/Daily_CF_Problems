/*
一共 20 个问题，但是有 100 个人
显示器是按照需要个数最多的那个人买的
需要选哪几个人才能覆盖所有的问题？
dp[i][j]: 从前 i 个人里面选，覆盖的问题集合为 j 的最小代价是多少
但是这个不包括显示器的信息，是否可以强制固定只在显示器个数不超过 cnt 的人里面选？
如果预先按照 k 的大小排序每个人，那么都不需要枚举 cnt 了
考虑刷表法，dp[i][j] 可以转移到哪些状态？dp[i + 1][j] 和 dp[i + 1][j | m[i + 1]] + x[i + 1]
*/

struct Person {
    LL x, k, s;

    bool operator<(const Person &o) const {
        return k < o.k;
    }
};

LL n, m, b, dp[3][M];
Person ps[N];

void meibao() {
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> ps[i].x >> ps[i].k >> cnt;
        int s = 0;
        for (int j = 1; j <= cnt; j++) {
            int id;
            cin >> id;
            s |= (1 << (id - 1));
        }
        ps[i].s = s;
    }    
    sort(ps + 1, ps + n + 1);
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    LL res = INFLL;
    for (int i = 0; i < n; i++) {
        int cur = i % 2;
        int ne = cur ^ 1;
        for (int j = 0; j < (1 << m); j++) {
            dp[ne][j] = min(dp[ne][j], dp[cur][j]);
            int mask = (j | ps[i + 1].s);
            dp[ne][mask] = min(dp[ne][mask], dp[cur][j] + ps[i + 1].first);
        }
        res = min(res, dp[cur][(1 << m) - 1] + ps[i].k * b);
    }
    res = min(res, dp[n % 2][(1 << m) - 1] + ps[n].k * b);
    if (res == INFLL) {
        res = -1;
    }
    cout << res << "\n";
}        
