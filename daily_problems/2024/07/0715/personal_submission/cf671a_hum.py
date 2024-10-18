import sys

input = lambda: sys.stdin.readline().rstrip()
from math import sqrt, inf

a1, b1, a2, b2, x, y = map(int, input().split())
n = int(input())
a, b, c = [], [], []


def dis(p1, p2, a1, b1):
  return sqrt((p1 - a1) * (p1 - a1) + (p2 - b1) * (p2 - b1))


for _ in range(n):
  p1, p2 = map(int, input().split())
  a.append(dis(p1, p2, a1, b1))
  b.append(dis(p1, p2, a2, b2))
  c.append(dis(p1, p2, x, y))

res = inf
a = [c[i] - a[i] for i in range(n)]
b = [c[i] - b[i] for i in range(n)]
ia = sorted(range(n), key=lambda k: a[k], reverse=True)
ib = sorted(range(n), key=lambda k: b[k], reverse=True)

res = min(res, sum(c) * 2 - a[ia[0]])
res = min(res, sum(c) * 2 - b[ib[0]])

for i in range(min(2, n)):
  for j in range(min(2, n)):
    if ia[i] != ib[j]:
      res = min(res, sum(c) * 2 - a[ia[i]] - b[ib[j]])

print(res)
