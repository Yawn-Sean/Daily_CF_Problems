n, k = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))

path = [[] for _ in range(n)]
for _ in range(n - 1):
  u, v = map(lambda x: int(x) - 1, input().split())
  path[u].append(v)
  path[v].append(u)

parent = [-1] * n
order = []
stk = [0]

while stk:
  u = stk.pop()
  order.append(u)

  for v in path[u]:
    if parent[u] != v:
      parent[v] = u
      stk.append(v)

sz = [0] * n
for u in a:
  sz[u] = 1

for u in reversed(order):
  if parent[u] >= 0:
    sz[parent[u]] += sz[u]

print(sum(min(2 * k - x, x) for x in sz))
