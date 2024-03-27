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

  def is_root(self, x):
    return self.p[x] < 0

  def count(self):
    cnt = 0
    for i in self.p:
      if i < 0:
        cnt += 1
    return cnt

  def size(self, x):
    return -self.p[self.find(x)]

  def to_bucket(self):
    n = len(self.p)
    ret = [[] for _ in range(n)]
    for i in range(n):
      r = self.find(i)
      ret[r].append(i)
    return ret


n, m, q = map(int, input().split())
dj = DJSet(n + m)

for _ in range(q):
  a, b = map(int, input().split())
  dj.merge(a - 1, b - 1 + n)

print(dj.count() - 1)
