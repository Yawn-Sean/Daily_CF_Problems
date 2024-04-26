/*
从前往后合并区间，维护区间合并前缀和区间合并后缀
然后枚举删除中间哪个即可
*/

int T;
LL l[N], r[N], n;
PLL pre[N], suf[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    
    pre[0] = {-INF, INF};
    for (int i = 1; i <= n; i++) {
        if (r[i] < pre[i - 1].x || l[i] > pre[i - 1].y) {
            pre[i].x = INF;
            pre[i].y = INF;
            continue;
        }
        pre[i].x = max(pre[i - 1].x, l[i]);
        pre[i].y = min(pre[i - 1].y, r[i]);
        // cout << i << " " << pre[i].x << " " << pre[i].y << "\n";
    }
    // cout << "\n";
    suf[n + 1] = {-INF, INF};
    for (int i = n; i > 0; i--) {
        if (r[i] < suf[i + 1].x || l[i] > suf[i + 1].y) {
            suf[i].x = -INF;
            suf[i].y = -INF;
            continue;
        }
        suf[i].x = max(suf[i + 1].x, l[i]);
        suf[i].y = min(suf[i + 1].y, r[i]);
        // cout << i << " " << suf[i].x << " " << suf[i].y << "\n";
    }
    
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (pre[i - 1].x > suf[i + 1].y || pre[i - 1].y < suf[i + 1].x) {
            continue;
        }
        LL ll = max(pre[i - 1].x, suf[i + 1].x);
        LL rr = min(pre[i - 1].y, suf[i + 1].y);
        res = max(res, rr - ll);
    }
    cout << res;
}         