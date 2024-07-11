import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
graph = [[] for _ in range(n)]
for _ in range(n - 1):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)

p = [-1] * n
dep = [0] * n
stack = [0]
dfs_order = []
while stack:
  u = stack.pop()
  dfs_order.append(u)
  for v in graph[u]:
    if p[u] == v:
      continue
    p[v] = u
    dep[v] = dep[u] + 1
    stack.append(v)

size = [0] * n
for u in reversed(dfs_order):
  size[u] += 1
  if u:
    size[p[u]] += size[u]

res = 0
cnt = 0
for i in range(n):
  if dep[i] % 2 == 0:
    cnt += 1
  res += size[i] * (n - size[i])

print((res + cnt * (n - cnt)) // 2)
