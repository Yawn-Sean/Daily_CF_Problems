/*
先算一块地上建两个相同的，最大能多大
旋转一下，默认 L <= W，再排个序，双关键字排序
再计算建在两块地的
枚举第 i 块地，则第 i + 1, ... n 块地的 L 都不小于这个的，所以其实就是找右边 W 最大的
第 1...i - 1 块地的 L 都不大于当前 L，W 可能大可能小
对于前缀中每个 W，维护最大的 L * W
查的时候，就是查 W <= 当前 W 的最大的面积
*/

PLL lands[N];
int n;
LL max_w[N], b[N], idx = 0;
BIT tr;

void meibao() {
    cin >> n;
    idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> lands[i].x >> lands[i].y;
        b[++idx] = lands[i].x;
        b[++idx] = lands[i].y;
        if (lands[i].x > lands[i].y) {
            swap(lands[i].x, lands[i].y);
        }
    }
    sort(lands + 1, lands + n + 1);
    sort(b + 1, b + idx + 1);
    LL res = 0;
    max_w[n + 1] = 0;
    for (int i = n; i > 0; i--) {
        max_w[i] = max(max_w[i + 1], lands[i].y);
    }
    tr.init(idx);
    for (int i = 1; i <= n; i++) {
        res = max(res, lands[i].x * lands[i].y);
        res = max(res, lands[i].x * lands[i].y);
        LL l = lands[i].x, w = lands[i].y;
        res = max(res, 2 * l * min(w, max_w[i + 1]));
        LL id_w = lower_bound(b + 1, b + idx + 1, w) - b;
        res = max(res, 2 * tr.query(id_w));
        tr.add(id_w, l * w);
    }
    if (res % 2 == 0) {
        cout << res / 2 << ".0\n";
    } else {
        cout << res / 2 << ".5\n";
    }
}
