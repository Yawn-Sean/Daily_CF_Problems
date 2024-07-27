import sys
from collections import deque
from math import inf

input = lambda: sys.stdin.readline().rstrip()

n, m, s, t = map(int, input().split())
graph = [[] for _ in range(n)]
vis = [[0] * n for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)
  vis[a][b] = 1
  vis[b][a] = 1
s -= 1
t -= 1


def bfs(u):
  que = deque()
  que.append(u)
  dis = [inf] * n
  dis[u] = 0
  while que:
    u = que.popleft()
    for v in graph[u]:
      if dis[v] == inf:
        dis[v] = dis[u] + 1
        que.append(v)
  return dis


res_s = bfs(s)
res_t = bfs(t)

res = 0
for i in range(n):
  for j in range(i + 1, n):
    if vis[i][j]:
      continue

    if res_s[i] + res_t[j] + 1 >= res_s[t] and res_s[j] + res_t[i] + 1 >= res_s[t]:
      res += 1

print(res)
