n = int(input())
dp = [[0] * (n + 1) for _ in range(n + 1)]

dp[0][0] = 1

mod = 10 ** 9 + 7

res = 0
for i in range(1, n + 1):
  for j in range(i + 1):
    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod

    if (i + j) % 2:
      res = (res + dp[i][j]) % mod

print(res)
