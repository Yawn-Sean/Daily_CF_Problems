/*
谁输了输出谁
有 a 个盒子和 b 个物品，则有 a^b 种方案
增加一个盒子，变成 (a + 1)^b，增加一个物品，变成 a^(b + 1)
显然指数函数比幂函数增长快，即增加盒子比增加物品方案数增加更快
b >= 2 时，a 不会超过 32000
不妨设 dp[i][j] 表示最开始 stas 处于 i 个盒子和 j 个球时，他自己能不能赢
枚举那些 i**j < n 的状态，然后计算，其中强制 i >= 2, j >= 2
如果 (i, j) 的下一步都是必胜态，则 (i, j) 是必败态
如果 (i, j) 的下一步存在必败态，则 (i, j) 是必胜态
(i, j) 的下一步要么是 (i + 1, j)，要么是 (i, j + 1)

下面单独考虑 i = 1 和 j = 1 的情况
i = 1 时
- 如果 j >= log2(n)，则不能加 i 了，这个时候就是平局
- 如果 j < log2(n)，则 i 和 j 都能加
j = 1 时
- 如果 i^2 >= n，则不能加 j 了， 这个时候假如 n - a 为偶数，则 M 输，否则 S 输
- 如果 i^2 < n，则 i 和 j 都能加
我们得到了两个初始状态 dp[1][log2(n)上取整] 和 dp[sqrt(n)上取整][1]
还要带上正常的那些边界，即 i**j < n 但 (i + 1)**j >= n 或 i**(j + 1) >= n 的那些，标记为 1
*/

int dp[N][M];
LL a, b, n, lgn, rootn;

void dfs(LL a, LL b) {
    if (dp[a][b] >= 0) {
        return;
    }

    if (a == 1 && b >= lgn) {
        dp[a][b] = 2;
        return;
    }

    if (b == 1 && a >= rootn) {
        dp[a][b] = (((n - a) % 2) ? 0 : 1);
        return;
    }

    LL val = 1;
    for (int i = 1; i <= b; i++) {
        val *= a;
    }
    if (val >= n) {
        dp[a][b] = 1;
        return;
    }

    dfs(a + 1, b);
    dfs(a, b + 1);

    if (dp[a + 1][b] == 0 || dp[a][b + 1] == 0) {
        dp[a][b] = 1;
    } else {
        if (dp[a + 1][b] == 2 && dp[a][b + 1] == 2) {
            dp[a][b] = 2;
        } else if (dp[a + 1][b] == 2) {
            dp[a][b] = 2;
        } else if (dp[a][b + 1] == 2) {
            dp[a][b] = 2;
        } else {
            dp[a][b] = 0;
        }
    }
}

void meibao() {
    cin >> a >> b >> n;
    memset(dp, -1, sizeof dp);
    for (lgn = 0; (1LL << lgn) < n; lgn++);
    rootn = sqrt(n);
    if (rootn * rootn < n) {
        rootn++;
    }
    dfs(a, b);
    int res = dp[a][b];
    if (res == 0) {
        cout << "Stas" << "\n";
    } else if (res == 1) {
        cout << "Masha" << "\n";
    } else {
        cout << "Missing" << "\n";
    }
}
