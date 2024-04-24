n = int(input())
a = list(map(int, input().split()))

graph = [[] for _ in range(n)]
for _ in range(n - 1):
  u, v, w = map(int, input().split())
  graph[u - 1].append((v - 1, w))
  graph[v - 1].append((u - 1, w))

p = [-1] * n
pw = [-1] * n
stack = [0]
dfs_order = []
while stack:
  u = stack.pop()
  dfs_order.append(u)
  for v, w in graph[u]:
    if v == p[u]:
      continue
    p[v] = u
    pw[v] = w
    stack.append(v)

res = 0
dis = [0] * n
for u in reversed(dfs_order):
  dis[u] = max(dis[u], a[u])
  res = max(res, dis[u])
  if p[u] != -1:
    dis[p[u]] = max(dis[p[u]], a[p[u]])
    tmp = max(0, dis[u] - pw[u])
    res = max(res, dis[p[u]] + tmp)
    dis[p[u]] = max(dis[p[u]], tmp + a[p[u]])

print(res)
