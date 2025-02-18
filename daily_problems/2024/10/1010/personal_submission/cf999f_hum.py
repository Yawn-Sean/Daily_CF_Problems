import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
n, k = map(int, input().split())
c = list(map(int, input().split()))
cnt = Counter(c)

f = list(map(int, input().split()))
h = list(map(int, input().split()))
m = n * k

dp = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
  for j in range(1, m + 1):
    for x in range(1, k + 1):
      if j - x >= 0:
        dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + h[x - 1])

cnt2 = Counter(f)

res = 0
for p, v in cnt2.items():
  res += dp[v][min(cnt[p], v * k)]

print(res)
