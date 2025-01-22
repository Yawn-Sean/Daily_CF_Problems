import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
n, k = map(int, input().split())
graph = [[] for _ in range(n)]
deg = [0] * n
for _ in range(n - 1):
  u, v = map(lambda x: int(x) - 1, input().split())
  graph[u].append(v)
  graph[v].append(u)
  deg[u] += 1
  deg[v] += 1

q = deque()
dis = [-1] * n
vis = [0] * n
for i in range(n):
  if deg[i] == 1:
    q.append(i)
    dis[i] = 0

cnt = [4] * n

while q:
  u = q.popleft()
  vis[u] = 1
  if cnt[u] < 3:
    print("No")
    exit()
  for v in graph[u]:
    if vis[v]:
      continue
    if dis[v] == -1:
      cnt[v] = 1
      dis[v] = dis[u] + 1
    elif dis[v] != dis[u] + 1:
      print("No")
      exit()
    else:
      cnt[v] += 1

    deg[v] -= 1
    if deg[v] == 1:
      q.append(v)

if max(dis) != k:
  print("No")
else:
  print("Yes")
