# Submission Link: https://codeforces.com/contest/1051/submission/266342049
def main():
    n, k = MII()

    dp = [[0] * (2 * n + 1) for _ in range(4)]

    dp[0][1] = 1
    dp[1][2] = 1
    dp[2][2] = 1
    dp[3][1] = 1

    mod = 998244353

    grid = [[0, 1, 1, 1],
            [0, 0, 2, 0],
            [0, 2, 0, 0],
            [1, 1, 1, 0]]

    for _ in range(n - 1):
        ndp = [[0] * (2 * n + 1) for _ in range(4)]
        
        for i in range(4):
            for j in range(k + 1):
                if dp[i][j]:
                    for ni in range(4):
                        ndp[ni][j+grid[i][ni]] += dp[i][j]
                        ndp[ni][j+grid[i][ni]] %= mod

        dp = ndp

    print(sum(dp[i][k] for i in range(4)) % mod)