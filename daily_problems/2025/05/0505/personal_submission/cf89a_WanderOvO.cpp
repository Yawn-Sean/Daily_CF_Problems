/*
只检查相邻两个的和
如何保持相邻两个和的不变性？
第一堆拿了 cnt 个，则第二堆应该增加 cnt 个，第三堆应该减少 cnt 个...
假如 n 是偶数，总的来说就拿不出来
假如 n 是奇数，则能偷出来一些
为了偷出来 1 个钻石，需要 (n + 1) / 2 次操作
*/

LL n, m, k, a[N];

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n % 2 == 0) {
        cout << "0\n";
    } else {
        LL res = m / ((n + 1) / 2) * k;
        for (int i = 1; i <= n; i += 2) {
            res = min(res, a[i]);
        }
        cout << res << "\n";
    }
}   
