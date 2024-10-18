/*
似乎只考虑移动到某个线段的端点就可以
dp[i][j]: 前 i 个线段，当前在 j 位置，最小代价是多少
暴力转移复杂度 O(n^3)，需要优化
abs(j - k) 可以分类讨论拆出来，然后把 j 从式子中提出来
对于 k >= j，有 dp[i][j] = min(dp[i - 1][k] + a[k]) - a[j] + j离亮灯的最近距离
对于 k < j，有 dp[i][j] = min(dp[i - 1][k] - a[k]) + a[j] + j离亮灯的最近距离
这两个 min 单独维护即可，维护前后缀
空间也有点卡，所以需要滚动数组
*/

int T;
int n, x;
PII segs[N];
int a[2 * N];
LL dp[2][2 * N], idx = 0;
LL pre[2 * N], suf[2 * N];

void solve1() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> segs[i].x >> segs[i].y;
        a[++idx] = segs[i].x;
        a[++idx] = segs[i].y;
    }
    a[++idx] = x;
    sort(a + 1, a + idx + 1);
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= idx; j++) {
            dp[i][j] = INFLL;
        }
    }
    for (int i = 1; i <= idx; i++) {
        if (a[i] == x) {
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        pre[0] = INFLL;
        int cur = (i & 1), last = 1 - cur;
        for (int k = 1; k <= idx; k++) {
            pre[k] = min(pre[k - 1], dp[last][k] - a[k]);
        }
        suf[idx + 1] = INFLL;
        for (int k = idx; k > 0; k--) {
            suf[k] = min(suf[k + 1], dp[last][k] + a[k]);
        }
        int l = segs[i].x, r = segs[i].y;
        for (int j = 1; j <= idx; j++) {
            dp[cur][j] = min(pre[j] + a[j], suf[j + 1] - a[j]) + (a[j] >= l && a[j] <= r ? 0 : min(abs(a[j] - l), abs(a[j] - r)));
        }
        for (int j = 1; j <= idx; j++) {
            dp[last][j] = dp[cur][j];
        }
    }
    LL res = INFLL;
    for (int i = 1; i <= idx; i++) {
        res = min(res, dp[0][i]);
    }
    cout << res << "\n";
}     
