from collections import deque


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


n, m = map(int, input().split())

a = [input() for _ in range(n)]

dj = DJSet(n + m)
for i in range(n):
  for j in range(n, n + m):
    if a[i][j - n] == '=':
      dj.merge(i, j)

graph = [[] for _ in range(n + m)]
deg = [0] * (n + m)
for i in range(n):
  for j in range(n, n + m):
    u = dj.find(i)
    v = dj.find(j)

    if a[i][j - n] == '>':
      graph[v].append(u)
      deg[u] += 1
    elif a[i][j - n] == '<':
      graph[u].append(v)
      deg[v] += 1

que = deque([i for i in range(n + m) if deg[i] == 0])
res = [1] * (n + m)

cnt = 0

while que:
  u = que.popleft()
  cnt += 1
  for v in graph[u]:
    res[v] = max(res[v], res[u] + 1)
    deg[v] -= 1
    if deg[v] == 0:
      que.append(v)

if cnt < n + m:
  print("No")
else:
  print("Yes")
  for i in range(n):
    print(res[dj.find(i)], end=' ')
  print()
  for i in range(m):
    print(res[dj.find(n + i)], end=' ')
