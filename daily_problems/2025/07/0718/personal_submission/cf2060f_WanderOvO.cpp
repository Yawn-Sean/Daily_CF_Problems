/*
k 并不大，所以数列中一定有很多 1
对于每个 x，其被分解成的非 1 数不会超过 17 个
如果枚举 x 然后分别算的话，似乎复杂度非常高，且有重复计算
素数的 x 很好办，因为有且仅有一个位置是这个数本身，其他的全都是 1
考虑 dp[i][j]: 将 i 拆成 j 个非 1 数的乘积的方案数(排列)
dp[1][0] = 1
dp[i][j] += dp[i / factor][j - 1]
预处理复杂度 O(k log k sqrt(k))，然后不会了

羊神提示：对于每一对 (x, n)，枚举 x 被拆成了几个非 1 的数，假设为 c 个
这 c 个非 1 的数将整个序列分成了 c + 1 段，其中每段的长度 >= 0
所以转化成了 x[1] + ... + x[c + 1] <= n - c 的非负整数解个数
也就是 y[1] + ... + y[c + 1] <= n + 1 的正整数解个数
由于 1 <= y[1] < y[1] + y[2] < ... < y[1] + ... + y[c + 1] <= n + 1
所以问题变成了从 [1, n + 1] 中选 c + 1 个不同的数的方案数，做了差分之后就是每个 y 了，显然是 C(n + 1, c + 1)

总的来说，预处理一个 dp 数组，然后对于输入的 k, n，枚举 1 <= x <= k，枚举非 1 的个数 c
则 res += dp[x][c] * C(n + 1, c + 1)，相当于第一步是看拆成 c 个非 1 数的排列数，第二步是剩下的 1 的分配方案数
即 res += dp[x][c] * (n + 1) * ... * (n - c + 1) / (2 * ... * (c + 1))

另外对于预处理，可以使用刷表法，这样可以把分解因数的根号复杂度变成总体调和级数的复杂度
*/

LL k, n, dp[N][M];
const int mod = 998244353;

LL qpow(LL a, LL b, LL MOD) {
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

void prepare() {
    dp[1][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j + 1 < M; j++) {
            for (int t = 2 * i; t < N; t += i) {
                dp[t][j + 1] += dp[i][j];
                dp[t][j + 1] %= mod;
            }
        }
    }
}

void meibao() {
    cin >> k >> n;
    cout << n << " ";
    for (LL x = 2; x <= k; x++) {
        LL res = 0;
        LL prod = n + 1;
        for (LL c = 0; c < M && c <= n; c++) {
            res += prod * dp[x][c];
            res %= mod;
            prod *= (n - c);
            prod %= mod;
            prod *= qpow(c + 2, mod - 2, mod);
            prod %= mod;
        }
        cout << res << " ";
    }
    cout << "\n";
}
