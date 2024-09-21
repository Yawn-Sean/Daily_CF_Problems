import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())

graph = [[] for _ in range(n)]
d = [0] * n
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)
  d[a] += 1
  d[b] += 1
dp = [1] * n
for u in range(n):
  for v in graph[u]:
    if v < u:
      dp[u] = max(dp[u], dp[v] + 1)
res = 0
for i in range(n):
  res = max(res, dp[i] * d[i])

print(res)