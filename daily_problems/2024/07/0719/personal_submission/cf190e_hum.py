import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)

search = set(range(n))
res = []

while search:
  u = search.pop()
  stack = [u]
  com = []
  while stack:
    u = stack.pop()
    com.append(u + 1)
    new_search = set()
    for v in graph[u]:
      if v in search:
        search.remove(v)
        new_search.add(v)
    for v in search:
      stack.append(v)
    search = new_search
  res.append(com)

print(len(res))
for com in res:
  print(len(com), *com)
