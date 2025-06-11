/*
看数据范围以及问题形式，显然的 dp
题目隐含了完成任务的顺序不重要，只看最后造成的结果
dp[i][j][k]: 前 i 个任务，赢了 j 个，剩余可用空间为 k 的概率
为了保证空间不会动态变化，可以优先把增加空间的那些任务解决了
如果是增加空间的任务：
dp[i][j][k] += p[i] * dp[i - 1][j - 1][k - a[i]]
dp[i][j][k] += (100 - p[i]) * dp[i - 1][j][k]
如果是增加容量的任务：
dp[i][j][k] += p[i] * dp[i - 1][j - 1][k + 1]
dp[i][j][k] += (100 - p[i]) * dp[i - 1][j][k]
注意到 k + 1 = k - a[i], a[i] = -1，所以转移方程是统一的
注意到第三维无需超过 200，所以空间不会爆
最后累加 dp[n][j][k]，其中 j >= l，k >= 0
*/ 

struct Object {
    int v;
    double p;

    bool operator<(const Object &o) const {
        return v > o.v;
    }
};

double dp[2][M][M];
LL n, l, m;
Object a[M];

void meibao() {
    cin >> n >> l >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].p;
        a[i].p /= 100;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
    }

    sort(a + 1, a + n + 1);

    memset(dp, 0, sizeof dp);
    dp[0][0][m] = 1;
    for (int i = 0; i < n; i++) {
        int cur = i % 2, ne = 1 - cur;
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < M; k++) {
                if (a[i + 1].v != -1) {
                    dp[ne][j + 1][min(k + a[i + 1].v, M - 1)] += dp[cur][j][k] * a[i + 1].p;
                } else {
                    if (k >= 1) {
                        dp[ne][j + 1][min(k + a[i + 1].v, M - 1)] += dp[cur][j][k] * a[i + 1].p;
                    }
                }
                dp[ne][j][k] += (1 - a[i + 1].p) * dp[cur][j][k];
            }
        }

        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < M; k++) {
                dp[cur][j][k] = 0;
            }
        }
    }
    double res = 0;
    for (int j = l; j <= n; j++) {
        for (int k = 0; k < M; k++) {
            res += dp[n % 2][j][k];
        }
    }
    cout << setprecision(20) << res << "\n";
}
