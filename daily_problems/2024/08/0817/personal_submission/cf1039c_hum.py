class DJSet:

  def __init__(self, n):
    self.p = [-1] * n

  def find(self, x):
    if self.p[x] < 0:
      return x
    nx = x
    while self.p[x] >= 0:
      x = self.p[x]
    while nx != x:
      self.p[nx], nx = x, self.p[nx]
    return x

  def merge(self, x, y):
    x = self.find(x)
    y = self.find(y)
    if x != y:
      if self.p[y] < self.p[x]:
        x, y = y, x
      self.p[x] += self.p[y]
      self.p[y] = x
    return x == y

  def reset(self, x):
    self.p[x] = -1


import sys

input = lambda: sys.stdin.readline().rstrip()
n, m, k = map(int, input().split())
c = list(map(int, input().split()))
edges = []
d = dict()
for i in range(m):
  u, v = map(lambda x: int(x) - 1, input().split())
  edges.append((u, v))
  d.setdefault(c[u] ^ c[v], []).append(i)

mod = 10 ** 9 + 7
lim = max(k, n) + 1
power = [1] * lim
for i in range(1, lim):
  power[i] = power[i - 1] * 2 % mod

res = (power[k] - len(d)) * power[n] % mod

dj = DJSet(n)

for x in d:
  cnt = n
  for i in d[x]:
    cnt -= 1 ^ dj.merge(edges[i][0], edges[i][1])

  res = (res + power[cnt]) % mod

  for i in d[x]:
    dj.reset(edges[i][0])
    dj.reset(edges[i][1])

print(res)
