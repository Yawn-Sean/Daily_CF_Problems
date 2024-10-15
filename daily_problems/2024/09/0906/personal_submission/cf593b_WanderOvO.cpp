/*
看有无两条直线的交点横坐标 x 在 (x1, x2) 中
题目保证所有直线斜率存在，且不存在重合的直线
不妨算一下所有直线在 (x1, x2) 上的端点值
两条直线，端点值分别相减，只要异号则说明相交，同号说明不相交，0 说明端点处相交（但本题要求开区间）
按照左端点值升序排序，相同则按右端点值升序排序
从左往右枚举，枚举到第 i 个直线时，我们考虑左端点值都 < 自己的那些直线
我们求一下这些直线右端点的最大值和最小值
只要最大和最小中有一个能凑出来异号，就对了
*/

int T;
LL n, x1, x2;
LL k[N], b[N];
PLL vals[N];

void solve1() {
    cin >> n >> x1 >> x2;

    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> b[i];
        vals[i].x = k[i] * x1 + b[i];
        vals[i].y = k[i] * x2 + b[i];
    }
    
    sort(vals + 1, vals + n + 1);

    LL mx = -INFLL, mn = INFLL;
    int l = 0;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        while (l + 1 < i && vals[l + 1].x < vals[i].x) {
            l++;
            mx = max(mx, vals[l].y);
            mn = min(mn, vals[i].y);
        }
        if (l != 0) {
            LL d1 = vals[i].y - mx, d2 = vals[i].y - mn;
            if (d1 < 0 || d2 < 0) {
                ok = true;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}     
