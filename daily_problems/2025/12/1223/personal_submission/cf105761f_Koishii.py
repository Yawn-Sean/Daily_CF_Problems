n, p = map(int, input().split())

p = min(p, 20)
dp = [[10 ** 9] * (n + 1) for _ in range(p + 1)]

for i in range(n + 1):
    dp[0][i] = 1

for i in range(1, p + 1):
    dp[i][0] = 1
    for j in range(1, n + 1):
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dp[i][j - 1])

for i in range(n + 1):
    if dp[p][i] >= n:
        print(i)
        break
