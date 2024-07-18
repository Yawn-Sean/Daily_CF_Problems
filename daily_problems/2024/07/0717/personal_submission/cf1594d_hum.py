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

  def to_bucket(self):
    n = len(self.p)
    ret = [[] for _ in range(n)]
    for i in range(n):
      r = self.find(i)
      if i >= n // 2:
        ret[r].append(i)
    return ret


import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n, m = map(int, input().split())
  dj = DJSet(n * 2)
  for _ in range(m):

    i, j, c = input().split()
    i = int(i) - 1
    j = int(j) - 1
    if c[0] == 'i':
      dj.merge(i, j + n)
      dj.merge(i + n, j)
    else:
      dj.merge(i, j)
      dj.merge(i + n, j + n)

  res = 0
  vis = [0] * (2 * n)
  cnt = [0] * n

  djb = dj.to_bucket()

  for i in range(n):
    if dj.find(i) == dj.find(i + n):
      print(-1)
      break
    res += max(len(djb[i]), len(djb[i + n]))
  else:
    print(res)
