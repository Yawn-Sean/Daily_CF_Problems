import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
s = []
for i in range(n):
  _, *x = list(map(lambda x: int(x) - 1, input().split()))
  s.append(x)

graph = [[] for _ in range(n)]
for _ in range(n - 1):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)

res = [-1] * m
vis = [0] * n
stack = [0]
while stack:
  u = stack.pop()
  vis[u] = 1
  used = set()
  for i in s[u]:
    if res[i] != -1:
      used.add(res[i])

  cur = 1
  for i in s[u]:
    if res[i] == -1:
      while cur in used:
        cur += 1
      res[i] = cur
      cur += 1

  for v in graph[u]:
    if not vis[v]:
      stack.append(v)

print(max(max(res), 1))
for i in res:
  print(1 if i == -1 else i, end=' ')
