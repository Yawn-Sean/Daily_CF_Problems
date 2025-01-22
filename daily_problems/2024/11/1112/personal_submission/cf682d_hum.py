n, m, k = map(int, input().split())
s = input()
t = input()
dp = [[[0] * (m + 1) for _ in range(n + 1)] for _ in range(k + 1)]

for i in range(1, k + 1):
  for j in range(1, n + 1):
    for l in range(1, m + 1):
      if s[j - 1] == t[l - 1]:
        dp[i][j][l] = max(dp[i][j - 1][l - 1], dp[i - 1][j - 1][l - 1]) + 1
  for j in range(1, n + 1):
    for l in range(1, m + 1):
      dp[i][j][l] = max(dp[i][j][l], dp[i][j - 1][l], dp[i][j][l - 1])

print(dp[k][n][m])
