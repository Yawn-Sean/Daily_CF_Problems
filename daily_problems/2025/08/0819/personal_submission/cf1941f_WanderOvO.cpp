/*
要求可以不加题目，或者加恰好 1 道
考虑最大的差和次大的差，假如相等，则不管怎么插入都一样了
假如不相等，考虑往最大的那两个中间插入一个新的题
假设是往 a[i] 和 a[i + 1] 中间插入，则我们希望插入一个最靠近 (a[i] + a[i + 1]) / 2 或 (a[i] + a[i + 1] + 1) / 2 的题
这两个可以都算一下，就不用讨论奇偶了
把 d 和 f 排个序，枚举 d[i]
想找最靠近 target 的，则相当于 f[j] 最靠近 target - d[i]，二分可以获得，看下左右两边的即可
target 取上面提到的那两个数，分别算一下
由于 a[i] <= d[i] + f[j] <= a[i + 1]，所以 a[i] - d[i] <= f[j] <= a[i + 1] - d[i]，这个条件也得判断一下
*/

LL n, m, k, a[N], d[N], f[N];

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> f[i];
    }

    sort(d + 1, d + m + 1);
    sort(f + 1, f + k + 1);

    LL d1 = 0, d2 = 0, pos = -1;
    for (int i = 1; i < n; i++) {
        LL d = a[i + 1] - a[i];
        if (d > d1) {
            d2 = d1;
            d1 = d;
            pos = i;
        } else if (d > d2) {
            d2 = d;
        }
    }

    if (d1 == d2) {
        cout << d1 << "\n";
        return;
    }

    LL res = d1;

    auto calc = [&] (LL target, int i) -> void {
        int p = lower_bound(f + 1, f + k + 1, target) - f;
        if (p <= k) {
            LL ff = f[p];
            LL s = ff + d[i];
            if (s <= a[pos + 1] && s >= a[pos]) {
                LL dist = max(a[pos + 1] - s, s - a[pos]);
                res = min(res, max(d2, dist));
            }
        }
        p--;
        if (p > 0) {
            LL ff = f[p];
            LL s = ff + d[i];
            if (s <= a[pos + 1] && s >= a[pos]) {
                LL dist = max(a[pos + 1] - s, s - a[pos]);
                res = min(res, max(d2, dist));
            }
        }
    };

    for (int i = 1; i <= m; i++) {
        LL target = (a[pos] + a[pos + 1]) / 2;
        target -= d[i];
        calc(target, i);
        target = (a[pos] + a[pos + 1] + 1) / 2;
        target -= d[i];
        calc(target, i);
    }

    cout << res << "\n";
}
