from math import inf

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

cost1 = [[inf] * n for _ in range(n)]
cost2 = [[inf] * n for _ in range(n)]

for i in range(n):
  for j in range(n):
    for k in range(m):
      cost1[i][j] = min(cost1[i][j], abs(grid[i][k] - grid[j][k]))
      if k:
        cost2[i][j] = min(cost2[i][j], abs(grid[i][k] - grid[j][k - 1]))
res = 0

lim = 1 << n
for s in range(n):
  dp = [[0] * lim for _ in range(n)]
  dp[s][1 << s] = inf

  for st in range(lim):
    for i in range(n):
      if dp[i][st]:
        if st >> i & 1:
          for j in range(n):
            if st >> j & 1 == 0:
              dp[j][st | (1 << j)] = max(dp[j][st | (1 << j)], min(dp[i][st], cost1[i][j]))

  for e in range(n):
    res = max(res, min(dp[e][lim - 1], cost2[s][e]))

print(res)
