import sys
from heapq import nlargest
from math import inf

input = lambda: sys.stdin.readline().rstrip()
n, k = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(n - 1):
  a, b, c = map(int, input().split())
  graph[a].append((b, c))
  graph[b].append((a, c))

parent = [-1] * n
stack = [0]
dfs_order = []
while stack:
  u = stack.pop()
  dfs_order.append(u)
  for v, w in graph[u]:
    if parent[u] == v:
      continue
    parent[v] = u
    stack.append(v)

f = [0] * n
g = [0] * n

for u in reversed(dfs_order):
  t0 = []
  t1 = []
  for v, w in graph[u]:
    if parent[v] == u:
      t0.append(f[v] + w)
      t1.append(g[v] + w)

  if t0:
    t = nlargest(k, t0)
    g[u] = sum(t)
    f[u] = g[u]
    if len(t) == k:
      f[u] -= t[-1]

    to_add = -inf
    for i in range(len(t0)):
      to_add = max(to_add, t1[i] - max(t0[i], t[-1]))

    g[u] += to_add

print(g[0])
