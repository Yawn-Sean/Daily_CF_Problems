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


n, m = map(int, input().split())
dj = DJSet(n)
cnt = 0
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  if dj.is_same(a, b):
    cnt += 1
  dj.merge(a, b)
  tmp = []
  for i in range(n):
    if dj.is_root(i):
      tmp.append(dj.size(i))
  tmp.sort(reverse=True)
  res = 0
  for i in range(min(len(tmp), cnt + 1)):
    res += tmp[i]

  print(res - 1)
