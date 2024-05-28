n = int(input())
a = list(map(int, input().split()))
m = sum(a)
a.sort()

dp = [0] * (m + 1)
dp[0] = 1

res = 0
mod = 998244353
for i in range(n):

  for s in range(m + 1):
    if s <= a[i]:
      res = (res + dp[s] * a[i]) % mod
    else:
      res = (res + (s + a[i] + 1) // 2 * dp[s]) % mod

  for j in range(m, -1, -1):
    if j - a[i] >= 0:
      dp[j] = (dp[j] + dp[j - a[i]]) % mod

print(res)
