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


import sys

input = lambda: sys.stdin.readline().rstrip()
n, m, k, w = map(int, input().split())
a = [[] for _ in range(k + 1)]
for i in range(k):
  for j in range(n):
    a[i + 1].append(input())

edges = []


def f(i, j):
  if i == 0 or j == 0:
    return n * m
  cnt = 0
  for x in range(n):
    for y in range(m):
      if a[i][x][y] != a[j][x][y]:
        cnt += 1
  return cnt * w


for i in range(k + 1):
  for j in range(i):
    cost = f(i, j)
    if cost <= n * m:
      edges.append((cost, i, j))

edges.sort()
res = 0
graph = [[] for _ in range(k + 1)]
dj = DJSet(k + 1)
for c, u, v in edges:
  if not dj.is_same(u, v):
    graph[u].append(v)
    graph[v].append(u)
    dj.merge(u, v)
    res += c

print(res)

stack = [0]
res = []
p = [-1] * (k + 1)
while stack:
  u = stack.pop()
  for v in graph[u]:
    if p[u] != v:
      stack.append(v)
      p[v] = u
      res.append((v, u))

for u, v in res:
  print(u, v)
