import sys
from math import inf

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = list(map(int, input().split()))
graph = [[] for _ in range(n)]
for _ in range(n - 1):
  x, y = map(lambda x: int(x) - 1, input().split())
  graph[x].append(y)
  graph[y].append(x)

stack = [0]
dfs_order = []
p = [-1] * n
while stack:
  u = stack.pop()
  if u >= 0:
    dfs_order.append(u)
    for v in graph[u]:
      if v == p[u]:
        continue
      p[v] = u
      stack.append(v)

acc = [0] * n
for u in reversed(dfs_order):
  acc[u] += a[u]
  if u:
    acc[p[u]] += acc[u]

cur_path = []

stack = [0]
dfs_order = []
t = -inf
res = -inf
while stack:
  u = stack.pop()
  if u >= 0:
    cur_path.append(u)
    res = max(res, t + acc[u])
    stack.append(~u)
    for v in graph[u]:
      if v == p[u]:
        continue
      stack.append(v)

  else:
    x = cur_path.pop()
    t = max(t, acc[x])

print("Impossible" if res == -inf else res)
