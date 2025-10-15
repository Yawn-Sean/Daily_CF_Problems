import sys

input = lambda: sys.stdin.readline().rstrip()
n, x, y = map(int, input().split())
x -= 1
y -= 1

graph = [[] for _ in range(n)]

for _ in range(n - 1):
  u, v = map(lambda x: int(x) - 1, input().split())
  graph[u].append(v)
  graph[v].append(u)

parent = [-1] * n
dfs_order = []

stack = [x]
while stack:
  u = stack.pop()
  dfs_order.append(u)
  for v in graph[u]:
    if parent[u] != v:
      parent[v] = u
      stack.append(v)

size = [1] * n

for u in reversed(dfs_order):
  if parent[u] != -1:
    size[parent[u]] += size[u]

t = size[y]

while parent[y] != x:
  y = parent[y]

t *= n - size[y]

print(n * (n - 1) - t)
