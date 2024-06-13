# TLE
import sys
from heapq import heappop, heappush
from math import inf

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)


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

    for v in graph[u]:
      if dist[v] > d + 1:
        dist[v] = d + 1
        heappush(hpq, (dist[v], v))

  return dist


dist = [[] for _ in range(n)]
for i in range(n):
  dis = dijkstra(graph, i)
  for j in range(n):
    if dis[j] == inf:
      dist[i].append(-1)
    else:
      dist[i].append(dis[j])

dist1 = [[] for _ in range(n)]
dist2 = [[] for _ in range(n)]
for i in range(n):
  for j in range(n):
    dist1[i].append((dist[i][j], j))
    dist2[j].append((dist[i][j], i))

for i in range(n):
  dist1[i].sort(key=lambda x: -x[0])
  dist2[i].sort(key=lambda x: -x[0])

res = (0, 0, 0, 0, 0)
for b in range(n):
  for c in range(n):
    if b == c or dist[b][c] == -1:
      continue
    for i in range(3):
      d1, a = dist2[b][i]
      if a == b or a == c or d1 == -1:
        continue
      for j in range(3):
        d2, d = dist1[c][j]
        if d == c or d == b or d == a or d2 == -1:
          continue
        if d1 + dist[b][c] + d2 > res[4]:
          res = (a, b, c, d, d1 + dist[b][c] + d2)

print(res[0] + 1, res[1] + 1, res[2] + 1, res[3] + 1)
