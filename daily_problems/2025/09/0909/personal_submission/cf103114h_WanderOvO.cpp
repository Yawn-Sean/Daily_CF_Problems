/*
m 个座位，n 个人，座位是环形排布的，至少隔一个人坐
m >= 2 * n 才能坐下
能坐下时，先考虑能选哪些座位，再全排列
我们要从环形的 m 个座位里选 n 个座位
选的这 n 个座位，把整个环形没选的剩下的部分分成了 n 段，每段都要 > 0 才行
环上似乎不太好处理，能否分类讨论改成链上做？发现可以分成下面三类
- 强制必选第一个位置，不能选最后一个位置，则相当于 x[1] + ... + x[n] = m - (n - 1) - 1 的正整数解个数 
- 强制必选最后一个位置，不能选第一个位置，则也相当于 x[1] + ... + x[n] = m - n 的正整数解个数 
- 第一个位置和最后一个位置都不能选，其他的随便选，则相当于 x[1] + ... + x[n + 1] = m - n 的正整数解个数（即序列上不间隔的方案数）
*/

const int mod = 1e9 + 7;
LL fact[N], invfact[N], n, m;

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

LL C(LL n, LL m) {
    if (n < m) return 0;
    return (fact[n] * invfact[m] % mod) * invfact[n - m] % mod;
}

LL calc(LL n, LL m) {
    return C(m - 1, n - 1);
}

void meibao() {
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << "1\n";
        return;
    }
    if (m < 2 * n) {
        cout << "0\n";
    } else {
        LL res = 0;
        res += calc(n, m - n);
        res += calc(n, m - n);
        res %= mod;
        res += calc(n + 1, m - n);
        res %= mod;
        res *= fact[n];
        res %= mod;
        cout << res << "\n";
    }
}  
