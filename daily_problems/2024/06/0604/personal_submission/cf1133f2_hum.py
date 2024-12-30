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

  def count(self):
    cnt = 0
    for i in self.p:
      if i < 0:
        cnt += 1
    return cnt


n, m, d = map(int, input().split())
a = []
rc = []
cnt0 = 0
dj = DJSet(n)
for _ in range(m):
  u, v = map(lambda x: int(x) - 1, input().split())
  a.append((u, v))
  if u == 0 or v == 0:
    cnt0 += 1
    if u:
      rc.append(u)
    else:
      rc.append(v)

  else:
    dj.merge(u, v)

if d > cnt0 or d < dj.count() - 1:
  print("NO")
else:
  print("YES")
  res = []
  tmp = []
  vis = set()
  dj2 = DJSet(n)
  for v in rc:
    if dj.find(v) not in vis:
      res.append((0, v))
      dj2.merge(0, v)
      vis.add(dj.find(v))
    else:
      tmp.append(v)
  while len(res) < d:
    v = tmp.pop()
    res.append((0, v))
    dj2.merge(0, v)

  for u, v in a:
    if u != 0 and v != 0 and not dj2.is_same(u, v):
      res.append((u, v))
      dj2.merge(u, v)

  for u, v in res:
    print(u + 1, v + 1)
