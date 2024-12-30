/*
假如有 a[i], a[j], i > j
则要想让这两个都能贡献，则必须有 a[i] - a[j] <= i - j
且 a[i] <= i, a[j] <= j, a[i] > a[j]
也就是说，i - a[i] >= j - a[j], a[i] <= i, a[j] <= j, a[i] > a[j], i > j
才能让 a[i] 和 a[j] 同时贡献

不等式有点多，我们看看能不能去掉一些
由 i - a[i] >= j - a[j], a[i] > a[j], 自然可以推出 i > j
对于 a[i] <= i, a[j] <= j, 其实相当于一个不等式 a[i] <= i
倘若不满足 a[i] <= i，则这个数必不可能对答案做出贡献，根本不需要考虑
所以我们可以只考虑 a[i] <= i 的数字

经过简化，其实只需要考虑 i - a[i] >= j - a[j] 且 a[i] > a[j] 即可

只考虑前 i 个，且第 i 个必须强制保留，最大 f 是多少？
则需要让所有满足 i - a[i] >= j - a[j] 且 a[i] > a[j] 的数字贡献给 f[i]
由于这两个条件就保证了 i > j，所以我们可以使用二维偏序的做法，先排序一维再做
*/

int T;
BIT tr;
int f[N], n, a[N], idx;
PII b[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i - a[i] >= 0) {
            b[++idx] = {i - a[i], a[i]};
        }
    }
    sort(b + 1, b + idx + 1);
    // n >= i - a[i] >= 0
    tr.init(n);
    tr.add(0, 0);
    f[0] = 0;
    int res = 0;
    for (int i = 1; i <= idx; i++) {
        f[i] = tr.query(b[i].y - 1) + 1;
        tr.add(b[i].y, f[i]);
        res = max(res, f[i]);
    }
    cout << res << endl;
}     