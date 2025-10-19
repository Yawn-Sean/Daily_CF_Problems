/*
选择的 m 要和每个 a[i] 的 gcd 都不为 1
a[i] <= 50，m 会有多大呢？
如果最小的 m <= 50，则直接枚举 m 算就好了
如果最小的 m > 50，则考虑得到 50 以内的素因子
50 以内只有 15 个素数
n = 5e5 很诈骗啊，实际上只有 50 个有用的数
我可以 2^15 枚举一下哪些素数出现了，然后 O(50) 判断一下是否真的可以
这 15 个数乘起来仍然在 long long 范围内
*/ 

int n, a[N], m;
LL res = INFLL;
int primes[50] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int cnt = 15;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(int u, LL prod) {
    if (u == cnt + 1) {
        for (int i = 1; i <= m; i++) {
            if (gcd(a[i], prod) == 1) {
                return;
            }
        }
        res = min(res, prod);
        return;
    }

    dfs(u + 1, prod);
    dfs(u + 1, prod * primes[u]);
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    m = unique(a + 1, a + n + 1) - a - 1;

    res = INFLL;
    dfs(1, 1);

    cout << res << "\n";
}   
