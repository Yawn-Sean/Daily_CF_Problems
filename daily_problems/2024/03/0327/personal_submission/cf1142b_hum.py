import sys

input = lambda: sys.stdin.readline().rstrip()

n, m, q = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))
last = [0] * n
for i in range(n):
  last[a[i]] = a[i - 1]

b = list(map(lambda x: int(x) - 1, input().split()))

idx = [-1] * n
fa = [-1] * m
for i in range(m):
  idx[b[i]] = i
  fa[i] = idx[last[b[i]]]

T = 20

dp = [[0] * m for _ in range(T)]

for i in range(m):
  dp[0][i] = fa[i]

for i in range(1, T):
  for j in range(m):
    if dp[i - 1][j] != -1:
      dp[i][j] = dp[i - 1][dp[i - 1][j]]
    else:
      dp[i][j] = -1

max_l = [-1] * m
for r in range(m):
  cur = r
  for i in range(T):
    if (n - 1) >> i & 1:
      cur = dp[i][cur]
      if cur == -1:
        break
  max_l[r] = cur

for r in range(1, m):
  max_l[r] = max(max_l[r - 1], max_l[r])

res = []
for _ in range(q):
  l, r = map(lambda x: int(x) - 1, input().split())
  if max_l[r] >= l:
    res.append(1)
  else:
    res.append(0)

print(*res, sep='')
