import sys

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
      if self.p[y] < self.p[x]:
        x, y = y, x
      self.p[x] += self.p[y]
      self.p[y] = x
    return x == y

  def is_same(self, x, y):
    return self.find(x) == self.find(y)


n, q = map(int, input().split())
dj = DJSet(n + 1)
ne = [i + 1 for i in range(n)]
for _ in range(q):
  t, x, y = map(lambda x: int(x) - 1, input().split())
  if t == 0:
    dj.merge(x, y)
  elif t == 1:
    while x < y:
      nx = ne[x]
      if nx > y:
        break
      dj.merge(x, nx)
      ne[x] = ne[y]
      x = nx
  else:
    print("YES" if dj.is_same(x, y) else "NO")
