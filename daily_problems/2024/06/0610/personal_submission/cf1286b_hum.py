n = int(input())
graph = [[] for i in range(n)]
r = 0
parent = [-1] * n
cs = []
for u in range(n):
  p, c = map(int, input().split())
  cs.append(c)
  if p == 0:
    r = u
  else:
    graph[p - 1].append(u)
    parent[u] = p - 1

stack = [r]
dfs_order = []
while stack:
  u = stack.pop()
  dfs_order.append(u)
  for v in graph[u]:
    stack.append(v)

order = []
s = [0] * n
for u in reversed(dfs_order):

  for v in graph[u]:
    s[u] += s[v]
  if s[u] < cs[u]:
    print("NO")
    exit()
  s[u] += 1
  order.insert(cs[u], u)

print("YES")

v2i = {v: i + 1 for i, v in enumerate(order)}
res = []
for i in range(n):
  res.append(v2i[i])
print(*res)
