## py TLE -> java

from heapq import heappop, heappush
from math import inf

t = int(input())

for _ in range(t):
  n, m = map(int, input().split())
  c = list(map(int, input().split()))
  a = []
  for _ in range(n):
    a.append(list(map(int, input().split())))

  root = a[0]


  def p(i, j, f):
    return (i - (1 - f)) * m + (j + 1)


  def p2(i):
    return n * m + i


  graph = [[] for _ in range(n * m + n)]
  for j in range(m):
    tmp = []
    for i in range(1, n):
      tmp.append((a[i][j], i))
    tmp.sort(reverse=True)

    graph[0].append((p(tmp[0][1], j, 0), max(0, a[0][j] - tmp[0][0])))
    graph[p(tmp[0][1], j, 0)].append((p2(tmp[0][1]), c[tmp[0][1]]))

    graph[p2(tmp[0][1])].append((p(tmp[0][1], j, 0), 0))

    # for x, y in pairwise(tmp):
    for i in range(n - 2):
      x = tmp[i]
      y = tmp[i + 1]
      graph[0].append((p(y[1], j, 0), max(0, a[0][j] - y[0])))

      graph[p(x[1], j, 0)].append((p(y[1], j, 0), x[0] - y[0]))
      graph[p(y[1], j, 0)].append((p(x[1], j, 0), 0))

      graph[p(y[1], j, 0)].append((p2(y[1]), c[y[1]]))
      graph[p2(y[1])].append((p(y[1], j, 0), 0))


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


  res = dijkstra(graph, 0)

  print(res[p2(n - 1)])
