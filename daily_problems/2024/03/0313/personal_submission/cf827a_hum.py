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


n = int(input())
s_s = []
idx = []
m = 0
for _ in range(n):
  s, _, *i = input().split()
  s_s.append(s)
  idx.append(i)
  m = max(m, len(s) + int(i[-1]) - 1)

ds = DJSet(m + 1)
res = ['a'] * m
for s, ids in zip(s_s, idx):
  for s_i in ids:
    i = int(s_i) - 1
    cur = i
    while ds.find(cur) < i + len(s):
      cur = ds.find(cur)
      res[cur] = s[cur - i]
      ds.merge(cur + 1, cur)

print("".join(res))
