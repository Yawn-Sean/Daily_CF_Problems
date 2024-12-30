import sys
from collections import defaultdict
from math import inf

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for idx in range(t):
  n = int(input())
  d = defaultdict(int)
  a = list(map(int, input().split()))
  for v in a:
    d[v] += 1
  m = min(d.values())
  res = inf
  for i in range(m + 1, 1, -1):
    tmp = 0
    for value in d.values():
      x, y = divmod(value, i)
      if y == 0:
        tmp += x
      else:
        if x + y < i - 1:
          tmp = inf
          break
        else:
          tmp += x + 1
    res = min(res, tmp)
  print(res)
