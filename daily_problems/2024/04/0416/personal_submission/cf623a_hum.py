import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
g = [[0] * n for _ in range(n)]
graph = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  g[a][b] = 1
  g[b][a] = 1

for i in range(n):
  for j in range(i + 1, n):
    if g[i][j] == 0:
      graph[i].append(j)
      graph[j].append(i)

col = [-1] * n
for i in range(n):
  if len(graph[i]) == 0:
    col[i] = 1
    continue
  if col[i] == -1:
    col[i] = 0
    stack = [i]
    while stack:
      u = stack.pop()
      for v in graph[u]:
        if col[v] == -1:
          col[v] = 2 - col[u]
          stack.append(v)
        elif col[v] == col[u]:
          print("No")
          exit()

for i in range(n):
  for j in range(i + 1, n):
    if g[i][j] == 1 and col[i] ^ col[j] == 2:
      print("No")
      exit()

res = [chr(ord('a') + i) for i in col]
print("Yes")
print(''.join(res))
