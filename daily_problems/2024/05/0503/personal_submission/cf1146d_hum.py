from heapq import heappop, heappush
from math import inf, gcd

m, a, b = map(int, input().split())

n = min(a + b, m)
mi = [inf] * (n + 1)
vis = [False] * (n + 1)

mi[0] = 0

hpq = [(mi[0], 0)]
while hpq:
  d, u = heappop(hpq)
  if vis[u]:
    continue
  vis[u] = True

  if u + a <= n and mi[u + a] > max(d, u + a):
    mi[u + a] = max(d, u + a)
    heappush(hpq, (mi[u + a], u + a))
  if u - b >= 0 and mi[u - b] > d:
    mi[u - b] = d
    heappush(hpq, (mi[u - b], u - b))

res = 0
for i in range(n + 1):
  if vis[i]:
    res += m - mi[i] + 1

if n != m:
  g = gcd(a, b)
  s, e = (n // g + 1) * g, m // g * g
  d = (e - s) // g + 1
  l, r = m - s + 1, m - e + 1
  res += d * (l + r) // 2

print(res)
