import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n, m = map(int, input().split())
  graph = [[] for _ in range(n)]
  edges = []
  for _ in range(n - 1):
    a, b, c = map(lambda x: int(x) - 1, input().split())
    c += 1
    if c != -1:
      graph[a].append((b, c))
      graph[b].append((a, c))
    edges.append((a, b))

  groups = [-1] * n
  res = [-1] * n

  for i in range(n):
    if res[i] == -1:
      res[i] = 0

      stack = [i]
      while stack:
        u = stack.pop()
        groups[u] = i
        for v, w in graph[u]:
          if res[v] == -1:
            res[v] = res[u] ^ w
            stack.append(v)

  graph = [[] for _ in range(n)]
  for _ in range(m):
    a, b, c = map(lambda x: int(x) - 1, input().split())
    c += 1
    if (res[a] ^ res[groups[a]]).bit_count() % 2:
      c ^= 1
    if (res[b] ^ res[groups[b]]).bit_count() % 2:
      c ^= 1
    a, b = groups[a], groups[b]
    graph[a].append((b, c))
    graph[b].append((a, c))

  col = [-1] * n
  f = True
  for i in range(n):
    if col[i] == -1:
      col[i] = 0
      stack = [i]
      while stack:
        u = stack.pop()
        for v, w in graph[u]:
          if w == 1:
            if col[v] == -1:
              col[v] = col[u] ^ 1
              stack.append(v)
            elif col[v] == col[u]:
              f = False
              break
          else:
            if col[v] == -1:
              col[v] = col[u]
              stack.append(v)
            elif col[v] != col[u]:
              f = False
              break
  if not f:
    print("NO")
    continue

  print("YES")
  for i in range(n):
    res[i] ^= col[groups[i]]
  for a, b in edges:
    print(a + 1, b + 1, res[a] ^ res[b])
