/*
dp[i][j][0/1][0/1]: 一共有 i 个字符，其中 j 个是 0，最后一个字符是 0/1，得到最终结果是 0/1 的方案数
res = dp[n + m][n][0][g] + dp[n + m][n][1][g]
dp[i][j][0][0] += dp[i - 1][j - 1][1][0]
dp[i][j][0][0] += dp[i - 1][j - 2][0][0]
...
复杂度 0(n * (n + m))，过不了

羊神提示：只要 i 位置的数是 1，且 i 不是最后一个，则操作到只剩下 1-i 的时候，i 位置一定是 0
这说明，i 后面所有数字随便填即可，反正到只剩下 1-i 时就是 0
显然，我们只关心第 1 个 1 的位置，只需要枚举第一个 1 的位置即可
特殊情况：没有 1，或者第一个 1 在最后一位，只需单独处理
假设第 i 个位置是第一个 1，则后面随便填有 C(n + m - i, m - 1) 种情况，最后算出来结果是多少呢？
如果 i 是奇数，则是 0，偶数则是 1
*/

int T;
LL n, m, g;
LL fact[N], invfact[N];

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

LL C(LL a, LL b) {
    int mod = MOD1;
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return (fact[a] * invfact[b] % mod) * invfact[a - b] % mod;
}

void solve1() {
    cin >> n >> m >> g;
    LL res = 0;
    int mod = MOD1;    
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i <= n + m; i++) {
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = qpow(fact[i], mod - 2, mod);
    }

    if (g == 0) {
        for (int i = 1; i < n + m; i += 2) {
            res += C(n + m - i, m - 1);
            res %= mod;
        }
        if (m == 1) {
            if ((n + 1) % 2 == 0) {
                res += 1;
                res %= mod;
            }
        }
        if (m == 0) {
            if (n % 2 != 0) {
                res++;
                res %= mod;
            }
        }
    } else {
        for (int i = 2; i < n + m; i += 2) {
            res += C(n + m - i, m - 1);
            res %= mod;
        }
        if (m == 1) {
            if ((n + 1) % 2 != 0) {
                res += 1;
                res %= mod;
            }
        }
        if (m == 0) {
            if (n % 2 == 0) {
                res++;
                res %= mod;
            }
        }
    }
    cout << res << "\n";
}    
