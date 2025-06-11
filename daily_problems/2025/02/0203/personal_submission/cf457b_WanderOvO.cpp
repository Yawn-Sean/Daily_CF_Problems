/*
小的往大的里面合并，代价更小一些，先把每个分区按照行数排序一下
把 a 最小的几个分区复制到 a 的某个大的分区里面，然后把另一个集群的数据在 a 保留的分区中各复制一份
会不会两个集群互相复制数据？不会，肯定不优
先钦定是 a 复制给 b，然后枚举 b 的前 i 小的数据，复制到比较大的堆里面，最后把 a 的数据复制若干份
反过来再钦定一下
答案上限不会超过 2e14，但是算的时候可能到 1e19
*/

ULL n, m, a[N], b[N];


void meibao() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);
    for (int i = 2; i <= m; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 2; i <= n; i++) {
        b[i] += b[i - 1];
    }

    ULL res = 2e14;
    for (int i = 0; i < m; i++) {
        res = min(res, a[i] + (m - i) * b[n]);
    }
    for (int i = 0; i < n; i++) {
        res = min(res, b[i] + (n - i) * a[m]);
    }
    cout << res << "\n";
}
