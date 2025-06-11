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

  def is_root(self, x):
    return self.p[x] < 0

  def size(self, x):
    return -self.p[self.find(x)]


n = int(input())
a = list(map(int, input().split()))
idx = sorted(range(n), key=lambda x: a[x])

vis = [0] * n
dj = DJSet(n)
cnt = [0] * (n + 1)
total = 0
cur = 0
res = -1
for i in idx:
  if i > 0 and vis[i - 1]:
    sz = dj.size(i - 1)
    cnt[sz] -= 1
    dj.merge(i - 1, i)
    total -= 1
  if i + 1 < n and vis[i + 1]:
    sz = dj.size(i + 1)
    cnt[sz] -= 1
    dj.merge(i + 1, i)
    total -= 1

  vis[i] = 1
  sz = dj.size(i)
  cnt[sz] += 1
  total += 1
  if cnt[sz] == total and total > cur:
    res = a[i] + 1
    cur = total

print(res)
