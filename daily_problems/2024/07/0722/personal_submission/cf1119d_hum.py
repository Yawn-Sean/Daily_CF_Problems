import sys
from bisect import bisect_right
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = list(map(int, input().split()))
a.sort()
g = []
for i in range(n - 1):
  if a[i + 1] - a[i] >= 2:
    g.append(a[i + 1] - a[i] - 1)
g.sort()
m = len(g)

s = list(accumulate(g, initial=0))
t = (a[-1] - a[0] + 1) - s[-1]

q = int(input())
res = []
for _ in range(q):
  l, r = map(int, input().split())
  l = r - l
  i = bisect_right(g, l)
  res.append(t + s[i] + (m - i) * l + l)

print(*res)
