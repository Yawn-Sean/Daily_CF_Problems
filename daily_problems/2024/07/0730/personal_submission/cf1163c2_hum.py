from collections import defaultdict
from math import gcd

n = int(input())
px, py = [], []
for _ in range(n):
  a, b = map(int, input().split())
  px.append(a)
  py.append(b)

lines = set()

for i in range(n):
  s = set()
  for j in range(i):
    dy = py[i] - py[j]
    dx = px[i] - px[j]
    g = gcd(dy, dx)
    dy //= g
    dx //= g
    if dy < 0 or (dy == 0 and dx < 0):
      dy *= -1
      dx *= -1
    lines.add((dy, dx, px[i] * dy - py[i] * dx))

d = defaultdict(int)
for dy, dx, b in lines:
  d[(dy, dx)] += 1

m = len(lines)
res = m * (m - 1) // 2
for v in d.values():
  res -= v * (v - 1) // 2

print(res)
