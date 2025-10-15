/*
初始只有 1 <= x < y <= m
目标 a[i] 可能会超过 m

目标卡片都是 (1, a) 的形式，如何得到 1?
(x, y) 行，那么 (x / 2, y / 2) 是否一定行？
(a, b) 能否转化为 (2a, 2b) 
b - a = d
2b - 2a = 2d
(a, b) 能得到 (a, b + d)，再做 a 次操作，就是 (2a, a + b + d) = (2a, 2b)
所以 (x, y) 行则 (x / 2, y / 2) 一定行
不妨 (x, y) 先把公共的 2 除掉了，然后再考虑

(x, y) 能得到怎样的卡片？
设 d = y - x
(x, y) = (x, x + d) 可生成 (x + d, x + 2d)，进而可以得到 (x, x + 2d)
x 和 x + 2d 奇偶性相同
我们想让 x 最后变成 1，因为目标的形式是这样的
((x + 1) / 2, (x + 2d + 1) / 2)
二者做差，结果差还是 d
是否初始的不包含公共 2 因子的 (x, y) 已经决定了最小的 d？手玩感觉是的
是否只与最小的 a[i] 有关？

(x, x + d) 能否得到 (1, d + 1)？其中 2 不能整除 gcd(x, x + d)
先得到 (x, x + 2d)，然后把 x 凑到一个偶数，除以 2，得到 (t, t + d)
t 一定 <= x，x 是偶数时显然，x 是奇数时我们总有 (x + 1) / 2 <= x
这个过程可以一直进行，这样 t 终究会变成 1

(1, d + 1) 又能转化成哪些呢？(1, k * d + 1)

综上，我们需要先看所有目标的 d[i] 们，求出这些 d[i] 们的最大公约数
然后对这个最大公约数做因数分解，考虑其奇数因子
当 y - x 的最大奇数因子能够整除最大公约数时，就是合理的构造
只需要枚举最大公约数的奇数因子，然后看看能乘多少 2^i 即可完成计数
*/

LL a[N], n, m;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    LL g = a[1] - 1;
    for (int i = 2; i <= n; i++) {
        g = gcd(g, a[i] - 1);
    }

    LL root = sqrt(g);
    LL res = 0;

    auto calc = [&] (LL val) -> LL {
        LL cnt = 0;
        while (1 + val <= m) {
            cnt += m - (1 + val) + 1;
            val *= 2;
        }
        return cnt;
    };

    for (LL i = 1; i <= root; i++) {
        if (g % i != 0) continue;
        if (i % 2 != 0) {
            res += calc(i);
        }
        LL j = g / i;
        if (j % 2 != 0 && j != i) {
            res += calc(j);
        }
    }
    cout << res << "\n";
}
