import sys

input = lambda: sys.stdin.readline().rstrip()
from bisect import bisect_left
from math import inf

n, m, k, q = map(int, input().split())
mi = [m] * n
ma = [-1] * n

for _ in range(k):
  r, c = map(lambda x: int(x) - 1, input().split())
  mi[r] = min(mi[r], c)
  ma[r] = max(ma[r], c)

pos = list(map(lambda x: int(x) - 1, input().split()))
pos.sort()

cur = 1
if mi[0] != m:
  dp0, dp1 = 2 * ma[0] - mi[0], ma[0]
  p0, p1 = mi[0], ma[0]
else:
  dp0, dp1 = 0, 0
  p0, p1 = 0, 0

for i in range(1, n):
  if mi[i] == m:
    cur += 1
  else:
    ndp0, ndp1 = inf, inf

    p = bisect_left(pos, p0)
    for idx in range(p - 1, p + 1):
      if 0 <= idx < q:
        ndp0 = min(ndp0, dp0 + abs(p0 - pos[idx]) + abs(pos[idx] - ma[i]) + ma[i] - mi[i],
                   dp1 + abs(p1 - pos[idx]) + abs(pos[idx] - ma[i]) + ma[i] - mi[i])
        ndp1 = min(ndp1, dp0 + abs(p0 - pos[idx]) + abs(pos[idx] - mi[i]) + ma[i] - mi[i],
                   dp1 + abs(p1 - pos[idx]) + abs(pos[idx] - mi[i]) + ma[i] - mi[i])

    p = bisect_left(pos, p1)
    for idx in range(p - 1, p + 1):
      if 0 <= idx < q:
        ndp0 = min(ndp0, dp0 + abs(p0 - pos[idx]) + abs(pos[idx] - ma[i]) + ma[i] - mi[i],
                   dp1 + abs(p1 - pos[idx]) + abs(pos[idx] - ma[i]) + ma[i] - mi[i])
        ndp1 = min(ndp1, dp0 + abs(p0 - pos[idx]) + abs(pos[idx] - mi[i]) + ma[i] - mi[i],
                   dp1 + abs(p1 - pos[idx]) + abs(pos[idx] - mi[i]) + ma[i] - mi[i])

    dp0, dp1 = ndp0 + cur, ndp1 + cur
    p0, p1 = mi[i], ma[i]
    cur = 1

print(min(dp0, dp1))
