import sys
input = lambda: sys.stdin.readline().strip()
mod = 998244353

n, k = map(int, input().split())
"""
dp[i][j][k] 表示前 i 列形成 j 个连通块，方案为 k
k = 0，两个白块
k = 1，上白下黑
k = 2，上黑下白
k = 3，两个黑块
"""
dp = [[[0 for _ in range(4)] for _ in range(2 * n + 1)] for _ in range(n + 1)]
dp[1][1][0] = dp[1][2][1] = dp[1][2][2] = dp[1][1][3] = 1
for i in range(2, n + 1):
    for j in range(i * 2 + 1):
        dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][max(j - 1, 0)][3]) % mod
        dp[i][j][1] = (dp[i - 1][max(j - 1, 0)][0] + dp[i - 1][j][1] + dp[i - 1][max(j - 2, 0)][2] + dp[i - 1][max(j - 1, 0)][3]) % mod
        dp[i][j][2] = (dp[i - 1][max(j - 1, 0)][0] + dp[i - 1][max(j - 2, 0)][1] + dp[i - 1][j][2] + dp[i - 1][max(j - 1, 0)][3]) % mod
        dp[i][j][3] = (dp[i - 1][max(j - 1, 0)][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3]) % mod
print(sum(dp[n][k][i] for i in range(4)) % mod)
