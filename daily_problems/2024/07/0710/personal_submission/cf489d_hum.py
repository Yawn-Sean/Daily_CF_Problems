import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)

cnt = [[0] * n for _ in range(n)]
for i in range(n):
  for j in graph[i]:
    for k in graph[j]:
      if i != k:
        cnt[i][k] += 1

res = 0
for i in range(n):
  for j in range(n):
    res += cnt[i][j] * (cnt[i][j] - 1) // 2

print(res)
