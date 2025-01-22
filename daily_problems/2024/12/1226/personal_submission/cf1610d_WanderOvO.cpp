/*
羊神提示：把数学式子写出来
sum(b[i] * x[i] + b[i] * (b[i] - 1) / 2) = 0，x[i] 为 b[i] 选择的首项
b[i] 确定了，需要求一组 x[i] 使得满足题意
我们只关心 b[i] 怎么取时 x[i] 有解
sum(b[i] * x[i]) = -sum(b[i] * (b[i] - 1) / 2)
需要 gcd(b[i]) | (-sum(b[i] * (b[i] - 1) / 2))
即求满足这个式子的 b 能搞出来多少个

羊神提示：gcd(b[1]...b[m]) 总是整除 b[1], b[2], ... b[m]
所以关心剩下的部分能不能被 2 整除
b[i] 中存在奇数，则 gcd = 1，其他数就可以随便选，所以可以选任意一个非空奇数集合，再选任意一个偶数集合（可以空）
倘若 b[i] 中没有奇数，我们枚举 gcd(b[i]) 中的 2 的幂次为 2^t，然后需要选 b
我们需要被 2^t 除完之后得到奇数的 b[i] 有偶数个，这要求我们选择偶数个幂次为 2^t 的，剩下的从高次里随便选
假设有 power_cnt[t] 个 2^t 幂次的，则有 2^(power_cnt[t] - 1) - 1 种非 0 偶数个选法
*/

LL n, a[N];

LL qpow(LL a, LL b, LL MOD) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        b >>= 1;
    }
    return res % MOD;
}

void meibao() {
    cin >> n;
    LL odd_cnt = 0;
    int power_cnt[33] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            odd_cnt++;
        } else {
            int cnt = 0;
            while (a[i] % 2 == 0) {
                cnt++;
                a[i] /= 2;
            }
            power_cnt[cnt]++;
        }
    }
    int mod = MOD1;
    LL res = (qpow(2, odd_cnt, mod) - 1) * qpow(2, n - odd_cnt, mod) % mod;
    LL sum = 0;
    for (int i = 1; i <= 30; i++) {
        sum += power_cnt[i];
    }
    for (int i = 1; i <= 30; i++) {
        sum -= power_cnt[i];
        if (power_cnt[i] > 0) {
            res += (qpow(2, power_cnt[i] - 1, mod) - 1) * (qpow(2, sum, mod)) % mod;
        }
        res %= mod;
    }
    res = (res + mod) % mod;
    cout << res << "\n";
}
