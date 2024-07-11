import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())

for _ in range(t):
  n = int(input())
  graph = [[] for _ in range(n)]
  d = dict()
  for i in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    graph[u].append(v)
    graph[v].append(u)
    d[(min(u, v), max(u, v))] = i

  p = [-1] * n
  dfs_order = []
  stack = [0]
  while stack:
    u = stack.pop()
    dfs_order.append(u)
    for v in graph[u]:
      if p[u] == v:
        continue
      p[v] = u
      stack.append(v)
  size = [1] * n
  res = []
  for u in reversed(dfs_order):
    if u == 0:
      break
    if size[u] == 3:
      c = (min(u, p[u]), max(u, p[u]))
      res.append(d[c] + 1)
    else:
      size[p[u]] += size[u]
  if size[0] == 3:
    print(len(res))
    print(*res)
  else:
    print(-1)
