/*
能否单独考虑每个人能贡献几次？
我们枚举最后一个会被包括进来的人，假设为 i，然后第一个不会被包括进来的人，假设为 j
则应该有放在 i 左边的总宽度 w 满足 p - a[i] - a[j] + 1 <= w <= p - a[i]
这样，用一个 DP，去求左边选 cnt 个人组成排列，宽度在这个范围内的方案数
然后，剩下的 n - cnt - 2 个人在右边就可以随便排了，算一个全排列
二者相乘，就是以 i, j 为分界点时的方案数
枚举 (i, j) 一定不会算重复
看一下复杂度，DP 的复杂度是 O(n^2 * p)，再套上外边的，总复杂度 O(n^4 * p)
复杂度有点极限，并且 50! 全排列已经爆了

羊神提示：50! 可以用浮点数存，且事实上只要枚举那个刚好超出的人就好了，枚举刚好放进去的那个人没用
假设第 i 个人刚好放不进去，则左边的总和应该满足 p - a[i] + 1 <= w <= p
*/

LL n, a[M], p;
double fact[M], dp[M][M][M];

double calc(LL a[], int lo, int hi) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= p; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j > 0 && k >= a[i]) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - a[i]] * j;
                }
            }
        }
    }

    double res = 0;
    for (int j = 0; j < n; j++) {
        for (int k = lo; k <= hi; k++) {
            res += (fact[n - j - 1] * dp[n - 1][j][k]) * j;
        }
    }

    return res;
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> p;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    double res = 0;
    for (int i = 1; i <= n; i++) {
        LL b[M];
        int idx = 1;
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                b[idx++] = a[j];
            }
        }
        res += calc(b, max(p - a[i] + 1, 0LL), p);
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    if (sum <= p) {
        res += n * fact[n];
    }

    cout << setprecision(15) << res / fact[n] << "\n";
}   
