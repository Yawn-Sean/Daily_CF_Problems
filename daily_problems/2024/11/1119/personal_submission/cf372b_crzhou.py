MAXN = 40 + 5

f = [[[[0] * MAXN for _ in range(MAXN)] for _ in range(MAXN)] for _ in range(MAXN)]
dp = [[[[0] * MAXN for _ in range(MAXN)] for _ in range(MAXN)] for _ in range(MAXN)]
sum_ = [[0] * MAXN for _ in range(MAXN)]

def chk(a, b, c, d):
    return sum_[c][d] - sum_[c][b - 1] - sum_[a - 1][d] + sum_[a - 1][b - 1] == 0


n, m, q = map(int, input().split())
grid = [input().strip() for _ in range(n)]

for i in range(1, n + 1):
    for j in range(1, m + 1):
        sum_[i][j] = (
            sum_[i - 1][j]
            + sum_[i][j - 1]
            - sum_[i - 1][j - 1]
            + (1 if grid[i - 1][j - 1] == '1' else 0)
        )

for a in range(1, n + 1):
    for b in range(1, m + 1):
        for c in range(a, n + 1):
            for d in range(b, m + 1):
                f[a][b][c][d] = (
                    f[a][b][c - 1][d]
                    + f[a][b][c][d - 1]
                    - f[a][b][c - 1][d - 1]
                    + chk(a, b, c, d)
                )

for a in range(n, 0, -1):
    for b in range(m, 0, -1):
        for c in range(n, a - 1, -1):
            for d in range(m, b - 1, -1):
                dp[a][b][c][d] = (
                    dp[a + 1][b][c][d]
                    + dp[a][b + 1][c][d]
                    - dp[a + 1][b + 1][c][d]
                    + f[a][b][c][d]
                )

for _ in range(q):
    a, b, c, d = map(int, input().split())
    print(dp[a][b][c][d])
