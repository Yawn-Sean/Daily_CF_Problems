/*
先分析一下操作：
初始化 current = start, sum = 0
- sum += a[current]
- a[current] = 0
- current = (current + step) % n
循环 n 轮
每个数至多贡献一次，且一旦再次走到某个已经走过的数，说明后边再走到的一定也都是之前走过的数
start 和 step 各有 n 种选择
我们可以考虑某个 a[i] 到底会贡献多少次
我们先固定 current，考虑啥样的 step 能走到 a[i]
(i + cnt * n - current) % step == 0，cnt >= 0
等下，是不是每个位置贡献次数一样呢？我们打个表试一下，发现确实如此
所以我们只看 i = 0 的情况，看有多少 (current, step) 对能走到 0 即可
i = 0 时，就是考虑 (cnt * n - current) % step == 0 的解的个数, cnt >= 0, n > current >= 0
其实就是 cnt * n % step == current，(current, step) 对的个数就是有多少种情况能走到 0

我们考虑循环如何产生，假如步长是 step，则当走了 n / gcd(n, step) 步时，会出现循环
对于这个循环，其有 n / gcd(n, step) 个元素，这里面每个元素作为起点都是可以的
所以 step 时有 n / gcd(n, step) 次访问 0 元素
*/

LL n, a[N];

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL qpow(LL a, LL b, LL mod) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res % mod;
}

void meibao() {
    cin >> n;
    const int mod = 1e9 + 7;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }

    LL cnt = 1;
    for (int step = 1; step < n; step++) {
        cnt += n / gcd(n, step);
        cnt %= mod;
    }
    sum *= cnt;
    sum %= mod;

    sum *= qpow(n * n % mod, mod - 2, mod);
    sum %= mod;
    cout << sum << "\n";
}   
