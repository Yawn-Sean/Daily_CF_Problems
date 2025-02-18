import sys
from bisect import bisect_left

input = lambda: sys.stdin.readline().rstrip()

n, h = map(int, input().split())
l, r = [], []
sa = [0]

for _ in range(n):
  a, b = map(int, input().split())
  l.append(a)
  r.append(b)
  sa.append(sa[-1] + b - a)

sd = [0]

for i in range(1, n):
  sd.append(sd[-1] + l[i] - r[i - 1])

res = h
for i in range(n):
  idx = bisect_left(sd, sd[i] + h)
  res = max(res, sa[idx] - sa[i] + h)

print(res)
