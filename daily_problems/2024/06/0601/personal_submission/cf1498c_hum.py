t = int(input())
mod = 10 ** 9 + 7
for _ in range(t):
  n, k = map(int, input().split())
  dp = [[0] * (k + 1) for _ in range(n + 1)]
  for j in range(1, k + 1):
    dp[0][j] = 1
    for i in range(1, n + 1):
      dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % mod

  print(dp[n][k])
