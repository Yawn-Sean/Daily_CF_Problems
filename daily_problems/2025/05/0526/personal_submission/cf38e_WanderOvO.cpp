/*
显然，最左边那个必须打钉子
dp[i][0/1]: 前 i 个球，其中第 i 个没打/打钉子的最小代价
dp[i][0] = min(dp[j][1] + x[j + 1] + ... + x[i] - (i - j) * x[j])
dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + c[i]
dp[1][0] = INF
dp[1][1] = c[1]
*/

struct Node {
    LL x, c;
};

LL dp[N][2], n;
Node a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].c;
    }

    sort(a + 1, a + n + 1, [&] (Node &o1, Node &o2) -> bool {
        return o1.x < o2.x;
    });

    memset(dp, 0x3f, sizeof dp);

    dp[1][0] = INFLL;
    dp[1][1] = a[1].c;
    for (int i = 2; i <= n; i++) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i].c;
        LL sum = 0;
        for (int j = i - 1; j > 0; j--) {
            sum += a[j + 1].x;
            dp[i][0] = min(dp[i][0], dp[j][1] + sum - (i - j) * a[j].x);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
}     
