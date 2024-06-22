import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)
a = list(map(int, input().split()))

stack = [i for i in range(n) if a[i] == 0]

b = [0] * n
res = []
while stack:
  u = stack.pop()
  b[u] += 1
  res.append(u + 1)
  for v in graph[u]:
    b[v] += 1
    if a[v] == b[v]:
      stack.append(v)

print(len(res))
print(*res)
