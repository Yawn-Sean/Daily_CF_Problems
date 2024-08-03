import sys
from heapq import heappush, heappop
from math import inf
from random import getrandbits

input = lambda: sys.stdin.readline().rstrip()

mod = getrandbits(32)


def dijkstra(graph, src):
  n = len(graph)
  dist = [inf] * n
  cnt = [0] * n
  vis = [False] * n
  hpq = [(0, src)]
  dist[src] = 0
  cnt[src] = 1

  while hpq:
    d, u = heappop(hpq)
    if vis[u]:
      continue
    vis[u] = True

    for v, w in graph[u]:
      if dist[v] == d + w:
        cnt[v] = (cnt[v] + cnt[u]) % mod
      if dist[v] > d + w:
        dist[v] = d + w
        cnt[v] = cnt[u]
        heappush(hpq, (dist[v], v))

  return dist, cnt


n, m, s, t = map(int, input().split())

graph1 = [[] for _ in range(n)]
graph2 = [[] for _ in range(n)]
edges = []
for _ in range(m):
  a, b, l = map(lambda x: int(x) - 1, input().split())
  l += 1
  graph1[a].append((b, l))
  graph2[b].append((a, l))
  edges.append((a, b, l))

dist1, cnt1 = dijkstra(graph1, s - 1)
dist2, cnt2 = dijkstra(graph2, t - 1)

d = dist1[t - 1]
c = cnt1[t - 1]

for a, b, l in edges:
  if dist1[a] + dist2[b] + l == d:
    if cnt1[a] * cnt2[b] % mod == c:
      print("YES")
    else:
      print("CAN 1" if l > 1 else "NO")
  else:
    x = d - dist1[a] - dist2[b] - 1
    if x <= 0:
      print("NO")
    else:
      print(f"CAN {l - x}")
