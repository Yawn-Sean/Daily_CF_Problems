n, k = map(int, input().split())

mod = 998244353

if k == 1:
  print(2)
  exit()

dp = [[[0] * 4 for _ in range(k + 1)] for _ in range(n)]

dp[0][1][0] = 1
dp[0][2][1] = 1
dp[0][2][2] = 1
dp[0][1][3] = 1


def f(x, y):
  if x == 1 and y == 2:
    return 2
  if x == 2 and y == 1:
    return 2
  if x == 0 or x == 3:
    if x != y:
      return 1
  return 0


for i in range(1, n):
  for j in range(1, k + 1):
    for cur in range(4):
      for pre in range(4):
        t = f(pre, cur)
        if j - t >= 0:
          dp[i][j][cur] = (dp[i][j][cur] + dp[i - 1][j - t][pre]) % mod

print(sum(dp[n - 1][k]) % mod)
