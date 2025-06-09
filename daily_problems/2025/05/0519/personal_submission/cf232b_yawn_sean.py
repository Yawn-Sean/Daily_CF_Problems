# Submission link: https://codeforces.com/contest/232/submission/320300541
def main():
    n, m, k = MII()

    mod = 10 ** 9 + 7
    combs = [[0] * (n + 1) for _ in range(n + 1)]
    combs[0][0] = 1

    for i in range(1, n + 1):
        combs[i][0] = 1
        for j in range(1, i + 1):
            combs[i][j] = combs[i - 1][j] + combs[i - 1][j - 1]

    x, y = divmod(m, n)

    dp = [0] * (k + 1)
    dp[0] = 1

    ndp = [0] * (k + 1)

    for i in range(n):
        for j in range(n + 1):
            val = pow(combs[n][j], x + 1 if i < y else x, mod)
            for cur in range(k - j + 1):
                if dp[cur]:
                    ndp[cur + j] = (ndp[cur + j] + dp[cur] * val) % mod
        
        for j in range(k + 1):
            dp[j] = ndp[j]
            ndp[j] = 0

    print(dp[k])