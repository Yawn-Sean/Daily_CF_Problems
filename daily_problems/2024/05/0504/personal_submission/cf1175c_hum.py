import sys

input = lambda: sys.stdin.readline().rstrip()
from math import inf

t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  a = list(map(int, input().split()))
  if k == 0:
    print(a[0])
    continue
  res, x = inf, a[0]
  for i in range(n - k):
    l, r = i, i + k
    if res > (a[r] - a[l] + 1) // 2:
      res = (a[r] - a[l] + 1) // 2
      x = a[l] + (a[r] - a[l] + 1) // 2
  print(x)
