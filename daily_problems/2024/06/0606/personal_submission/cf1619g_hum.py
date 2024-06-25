from collections import defaultdict
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
      if self.p[y] < self.p[x]:
        x, y = y, x
      self.p[x] += self.p[y]
      self.p[y] = x
    return x == y


t = int(input())

for _ in range(t):
  input()
  n, k = map(int, input().split())

  r = defaultdict(list)
  c = defaultdict(list)

  ti = []
  for i in range(n):
    x, y, tt = map(int, input().split())
    ti.append(tt)
    r[x].append((y, i))
    c[y].append((x, i))

  dj = DJSet(n)
  for _, l in r.items():
    l.sort()
    for i in range(len(l) - 1):
      if l[i + 1][0] - l[i][0] <= k:
        dj.merge(l[i][1], l[i + 1][1])

  for _, l in c.items():
    l.sort()
    for i in range(len(l) - 1):
      if l[i + 1][0] - l[i][0] <= k:
        dj.merge(l[i][1], l[i + 1][1])

  m = [inf] * n
  for i in range(n):
    root = dj.find(i)
    m[root] = min(m[root], ti[i])

  m = [x for x in m if x != inf]

  m.sort(reverse=True)
  res = -1
  for i in range(len(m)):
    if m[i] > res:
      res += 1

  print(res)
