import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
edges = []
graph = [[] for _ in range(n)]
for _ in range(n - 1):
  a, b, c = map(lambda x: int(x) - 1, input().split())
  edges.append((a, b, c + 1))
  graph[a].append(b)
  graph[b].append(a)

stack = [0]
p = [-1] * n
dfs_order = []
while stack:
  u = stack.pop()
  dfs_order.append(u)
  for v in graph[u]:
    if v == p[u]:
      continue
    p[v] = u
    stack.append(v)

size = [0] * n
for u in reversed(dfs_order):
  if u:
    size[u] += 1
    size[p[u]] += size[u]


def f(son, fa, c):
  if son == p[fa]:
    son, fa = fa, son
  s1, s2 = size[son], n - size[son]

  return c * (s1 * (s1 - 1) // 2 * s2 + s2 * (s2 - 1) // 2 * s1) * 2


res = 0

for a, b, c in edges:
  res += f(a, b, c)

s = n * (n - 1) * (n - 2) // 6

q = int(input())
for _ in range(q):
  i, c = map(int, input().split())
  a, b, oc = edges[i - 1]
  edges[i - 1] = (a, b, c)
  res -= f(a, b, oc)
  res += f(a, b, c)
  print(res / s)
