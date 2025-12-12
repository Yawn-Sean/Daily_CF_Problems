#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

/*
我们考虑第 i 个位置填 j，能贡献几次答案
要求前 i - 1 个位置必须都 >= j，第 i 个位置恰好是 j，后边随意
所以有 (k - j + 1)^(i - 1) * k^(n - i)
考虑如何快速对这个东西进行求和
如果先枚举 i 再枚举 j
则 k^(n - i) 可以提出来，本质上就是对 (k - j + 1)^(i - 1) 进行求和
而这个东西恰好是 1^(i - 1) + ... + k^(i - 1)
这个东西没那么容易处理

如果先枚举 j 再枚举 i
则可以看成是公比为 (k - j + 1) / k，首项为 k^(n - 1) 的等比数列求前 n 项和
我们可以使用公式快速算出来这个和，外层枚举的 j 只有 3e5，完全可以 
这个东西的坑点在于 (k - j + 1) / k 可能是 1，需要特判是 n * k^(n - 1)
*/

LL n, k;
const int mod = 998244353;

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

LL inv(LL a) {
    return qpow(a, mod - 2, mod);
}

void solve() {
    cin >> n >> k;
    LL res = n * qpow(k, n - 1, mod) % mod;
    for (int j = 2; j <= k; j++) {
        LL q = (k - j + 1) * inv(k) % mod;
        LL a1 = qpow(k, n - 1, mod);
        LL qn = qpow(q, n, mod);
        res += inv(1 - q) * a1 % mod * (1 - qn) % mod;
        res %= mod;
    }
    cout << (res % mod + mod) % mod << "\n";
}
