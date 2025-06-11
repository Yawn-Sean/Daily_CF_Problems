from collections import Counter


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

  def is_same(self, x, y):
    return self.find(x) == self.find(y)

  def is_root(self, x):
    return self.p[x] < 0

  def size(self, x):
    return -self.p[self.find(x)]


import sys

input = lambda: sys.stdin.readline().rstrip()

n, m, k = map(int, input().split())
c = list(map(int, input().split()))
dj = DJSet(n)

for _ in range(m):
  l, r = map(lambda x: int(x) - 1, input().split())
  dj.merge(l, r)

cnt = [Counter() for _ in range(n)]
for i in range(n):
  cnt[dj.find(i)][c[i]] += 1

res = n
for x in cnt:
  if x:
    res -= max(x.values())

print(res)
