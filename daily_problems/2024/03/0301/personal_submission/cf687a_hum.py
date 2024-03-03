n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].append(b)
  graph[b].append(a)

col = [-1] * n
stack = []
for i in range(n):
  if col[i] == -1:
    col[i] = 0
    stack.append(i)
    while stack:
      u = stack.pop()
      for v in graph[u]:
        if col[v] == -1:
          stack.append(v)
          col[v] = 1 - col[u]
        elif col[v] == col[u]:
          print(-1)
          exit()

res = [i + 1 for i in range(n) if col[i] == 1]
print(len(res))
print(*res)

res = [i + 1 for i in range(n) if col[i] == 0]
print(len(res))
print(*res)
