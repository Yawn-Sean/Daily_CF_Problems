import sys
from math import inf

input = lambda: sys.stdin.readline().rstrip()


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
      self.p[x] += self.p[y]
      self.p[y] = x
    return x == y

  def is_same(self, x, y):
    return self.find(x) == self.find(y)


t = int(input())
for _ in range(t):
  n, m, k = map(int, input().split())
  edges = []
  for i in range(m):
    a, b, c = map(int, input().split())
    edges.append((c, a - 1, b - 1))

  edges.sort()
  dj = DJSet(n)
  m = 0
  res = 0
  for c, a, b in edges:
    if not dj.is_same(a, b):
      m = max(c, m)
      dj.merge(a, b)
      if c > k:
        res += c - k

  if m < k:
    res = inf
    for c, a, b in edges:
      res = min(res, abs(k - c))

  print(res)
