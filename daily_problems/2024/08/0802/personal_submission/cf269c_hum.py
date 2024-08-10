import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
graph = [[] for _ in range(n)]
fr = [0] * m
deg = [0] * n
for i in range(m):
  a, b, c = map(lambda x: int(x) - 1, input().split())
  c += 1
  graph[a].append((b, c, i))
  graph[b].append((a, c, i))
  deg[a] += c
  deg[b] += c
  fr[i] = a

for i in range(n - 1):
  deg[i] //= 2
res = [-1] * m

deg[0] = 0

que = deque([0])

while que:
  u = que.popleft()
  for v, c, i in graph[u]:
    if deg[v] == 0:
      continue
    if res[i] == -1:
      if fr[i] == u:
        res[i] = 0
      else:
        res[i] = 1
      deg[v] -= c
      if deg[v] == 0:
        que.append(v)

print(*res, sep='\n')
