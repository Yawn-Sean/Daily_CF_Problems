/*
x[2] 做素因数分解，其中某个素数就是当初 < x[1] 的那个数
选择一个素数 p，选择一个 > p 的 x[1]，然后对 x[1] 素因数分解
由于要最小化 x[0]，所以事实上就是选最小的 p | x[1]，然后 x[0] = p + 1 即可
回过头来看一下我们要做的事情：
- 枚举 x[2] 的某个素因数 p
- x[2] >= x[1] >= x[2] - p + 1，p 越大这个区间范围越大，且区间互相包含，所以事实上只要考虑最大的 p
- 对于这个范围内的 x[1]，考虑其素因子 q，则有 x[1] >= x[0] >= x[1] - q + 1
- 想要 x[0] 最小，则 x[1] - q + 1 要最小，即 q 最大
- 有一个特殊情况是 x[1] 为素数时，x[0] 也只可能等于 x[1]
- 我们预处理 1e6 范围内所有数的最大素因子
- 则 x[2] 的最大素因子 p 确定了 x[1] 的范围
- 在这些 x[1] 中找最小值
*/

int minp[N], maxp[N], self_minus_maxp[N], n;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        minp[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (minp[i] != i) continue;
        for (int j = i; j <= n; j += i) {
            if (minp[j] == j) {
                minp[j] = i;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        int val = i;
        while (val > 1) {
            int p = minp[val];
            maxp[i] = p;
            val /= p;
        }
    }

    for (int i = 2; i <= n; i++) {
        self_minus_maxp[i] = i;
        if (i != maxp[i])
            self_minus_maxp[i] = i - maxp[i];
    }
    for (int i = n - 1; i > 0; i--) {
        self_minus_maxp[i] = min(self_minus_maxp[i], self_minus_maxp[i + 1]);
    }

    int maxx1 = n, minx1 = n - maxp[n] + 1;
    // cout << maxx1 << " " << minx1 << '\n';
    cout << self_minus_maxp[minx1] + 1 << "\n";
}   
