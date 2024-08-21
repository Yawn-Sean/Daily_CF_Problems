import sys
from heapq import heappop, heappush
from math import inf

input = lambda: sys.stdin.readline().rstrip()
n, m, k = map(int, input().split())
graph = [[] for _ in range(n)]
for i in range(m):
  a, b, c = map(lambda x: int(x) - 1, input().split())
  c += 1
  graph[a].append((b, c, i))
  graph[b].append((a, c, i))


def dij(src):
  dist = [inf] * n
  dist[src] = 0
  vis = [False] * n
  hpq = [(0, src, -1)]
  while hpq:
    d, u, fr = heappop(hpq)
    if vis[u]:
      continue
    vis[u] = True
    res.append(fr + 1)
    if len(res) > k:
      return
    for v, w, i in graph[u]:
      if dist[v] > dist[u] + w:
        dist[v] = dist[u] + w
        heappush(hpq, (dist[v], v, i))


res = []
dij(0)

print(len(res) - 1)
print(*res[1:])
