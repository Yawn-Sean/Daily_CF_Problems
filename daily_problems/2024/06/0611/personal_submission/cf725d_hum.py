from heapq import heappush, heappop
from math import inf
import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
t, w = map(int, input().split())
a = []
for i in range(n - 1):
  x, y = map(int, input().split())
  a.append((x, y))

a.sort(key=lambda x: -x[0])
hpq = []
res = inf
j = 0
while True:
  while j < n - 1 and a[j][0] > t:
    heappush(hpq, a[j][1] - a[j][0] + 1)
    j += 1
  res = min(res, len(hpq) + 1)
  if hpq and hpq[0] <= t:
    t -= heappop(hpq)
  else:
    break

print(res)
