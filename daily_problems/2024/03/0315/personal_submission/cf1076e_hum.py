import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
graph = [[] for _ in range(n)]
for _ in range(n - 1):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)

q = int(input())
updates = [[] for _ in range(n)]
for _ in range(q):
  u, d, x = map(int, input().split())
  updates[u - 1].append((d, x))

diff = [0] * n
dep = [-1] * n
dep[0] = 0

res = [0] * n

stack = [0]
cur = 0
while stack:
  u = stack.pop()
  if u >= 0:
    stack.append(~u)
    for d, x in updates[u]:
      diff[dep[u]] += x
      if dep[u] + d + 1 < n:
        diff[dep[u] + d + 1] -= x
    cur += diff[dep[u]]
    res[u] = cur
    for v in graph[u]:
      if dep[v] == -1:
        dep[v] = dep[u] + 1
        stack.append(v)
  else:
    u = ~u
    cur -= diff[dep[u]]
    for d, x in updates[u]:
      diff[dep[u]] -= x
      if dep[u] + d + 1 < n:
        diff[dep[u] + d + 1] += x

print(*res, sep=' ')
