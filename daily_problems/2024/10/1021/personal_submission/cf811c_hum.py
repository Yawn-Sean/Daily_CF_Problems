n = int(input())
a = list(map(int, input().split()))
m = max(a)
ls, rs = [0] * (m + 1), [0] * (m + 1)
vis = [0] * (m + 1)
for i in range(n):
  rs[a[i]] = i
for i in range(n - 1, -1, -1):
  ls[a[i]] = i

dp = [0] * (n + 1)

for i in range(n):
  r = 0
  tmp = 0
  for j in range(i, n):
    if ls[a[j]] < i:
      break

    if not vis[a[j]]:
      tmp ^= a[j]
      vis[a[j]] = 1
    if rs[a[j]] > r:
      r = rs[a[j]]

    if j == r:
      dp[j + 1] = max(dp[j + 1], dp[i] + tmp)

  dp[i + 1] = max(dp[i + 1], dp[i])

  for j in range(m + 1):
    vis[j] = 0

print(dp[n])
