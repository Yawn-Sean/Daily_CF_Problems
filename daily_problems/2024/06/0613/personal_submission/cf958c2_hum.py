n, k, p = map(int, input().split())
a = list(map(int, input().split()))
s = 0
ma = [[-1] * (k + 1) for _ in range(p)]
dp = [[0] * (k + 1) for _ in range(n)]

ma[0][0] = 0

for i in range(n):
  s += a[i]
  s %= p
  for j in range(1, k + 1):
    for v in range(p):
      if ma[v][j - 1] != -1:
        dp[i][j] = max(dp[i][j], ma[v][j - 1] + (s - v) % p)
        ma[s][j] = max(ma[s][j], dp[i][j])

print(dp[n - 1][k])
