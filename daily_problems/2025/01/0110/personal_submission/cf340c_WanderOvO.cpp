/*
假设 a[i] 是单调递增的，则 a[i + 1] - a[i] 贡献了多少次
当前点选 [1, i] 中的某个，下一个点选 [i + 1, n] 中的某个，就会贡献，反之也可以
在所有的排列中，a[i + 1] - a[i] 发生了多少次呢？
考虑所有排列中，满足一个 [1, i] 中的点和一个 [i + 1, n] 中的点相邻出现了多少次
C(i, 1) * C(n - i, 1) * 2! * (n - 1)! 次
特别的，选第一个点是从 0 出发的，所以还要加上每个 a[i] 各 (n - 1)! 次
最后总和要除以 n!
(sum(i * (n - i) * 2 * (n - 1)! * (a[i + 1] - a[i])) + sum(a[i] * (n - 1)!) / n!
(sum(i * (n - i) * 2 * (a[i + 1] - a[i])) + sum(a[i]) / n
*/

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    for (int i = 1; i < n; i++) {
        sum += i * (n - i) * 2 * (a[i + 1] - a[i]);
    }
    LL g = gcd(sum, n);
    if (g != 0) {
        sum /= g;
        n /= g;
    }
    cout << sum << " " << n << "\n";
}
