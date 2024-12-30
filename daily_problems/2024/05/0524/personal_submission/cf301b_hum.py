from heapq import heappop, heappush
from math import inf


def dijkstra(graph, src):
  n = len(graph)
  dist = [inf] * n
  vis = [False] * n
  hpq = [(0, src)]
  dist[src] = 0

  while hpq:
    d, u = heappop(hpq)
    if vis[u]:
      continue
    vis[u] = True

    for v, w in graph[u]:
      if dist[v] > d + w:
        dist[v] = d + w
        heappush(hpq, (dist[v], v))

  return dist


n, d = map(int, input().split())

graph = [[] for _ in range(n)]

a = [0] + list(map(int, input().split())) + [0]
p = []
for _ in range(n):
  x, y = map(int, input().split())
  p.append((x, y))

for i in range(n):
  for j in range(n):
    if i != j:
      graph[i].append((j, d * (abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1])) - a[j]))
      graph[j].append((i, d * (abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1])) - a[i]))

dist = dijkstra(graph, 0)
print(dist[n - 1])
