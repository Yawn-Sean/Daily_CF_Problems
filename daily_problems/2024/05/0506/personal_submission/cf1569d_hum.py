import sys
from bisect import bisect_left
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n, m, k = map(int, input().split())

  xs = list(map(int, input().split()))
  ys = list(map(int, input().split()))

  cnt1 = [Counter() for _ in range(m)]
  cnt2 = [Counter() for _ in range(n)]

  for _ in range(k):
    x, y = map(int, input().split())
    px = bisect_left(xs, x)
    py = bisect_left(ys, y)
    if xs[px] == x and ys[py] == y:
      continue
    if xs[px] == x:
      cnt1[py][x] += 1
    else:
      cnt2[px][y] += 1

  res = 0
  for i in range(m):
    s = 0
    for v in cnt1[i].values():
      res += s * v
      s += v

  for i in range(n):
    s = 0
    for v in cnt2[i].values():
      res += s * v
      s += v

  print(res)
