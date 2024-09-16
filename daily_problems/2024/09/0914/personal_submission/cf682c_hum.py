import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = list(map(int, input().split()))
edge = [0]
graph = [[] for _ in range(n)]
for i in range(1, n):
  p, c = map(int, input().split())
  edge.append(c)
  graph[p - 1].append(i)

dp = [0] * n

stack = [0]

res = 0

while stack:
  u = stack.pop()
  res += 1
  for v in graph[u]:
    dp[v] = max(0, dp[u]) + edge[v]
    if dp[v] <= a[v]:
      stack.append(v)

print(n - res)
