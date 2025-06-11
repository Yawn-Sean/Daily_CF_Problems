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


n, m = map(int, input().split())
if m == 0:
  print("Nice work, Dima!")
  exit()

a = []
b = []
l = []
r = []
for _ in range(m):
  aa, bb, ll, rr = map(lambda x: int(x) - 1, input().split())
  a.append(aa)
  b.append(bb)
  l.append(ll)
  r.append(rr)


def check(ll, rr):
  dj = DJSet(n)
  for i in range(m):
    if l[i] <= ll and rr <= r[i]:
      dj.merge(a[i], b[i])

  return dj.is_same(0, n - 1)


e = max(r)
res = 0
for i in sorted(set(l)):
  left = i - 1
  right = e
  while left < right:
    if right - i + 1 <= res:
      break
    mid = left + right + 1 >> 1
    if check(i, mid):
      left = mid
    else:
      right = mid - 1
  res = max(res, left - i + 1)
if res == 0:
  print("Nice work, Dima!")
else:
  print(res)
