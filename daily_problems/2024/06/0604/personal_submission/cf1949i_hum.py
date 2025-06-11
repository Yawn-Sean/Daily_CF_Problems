n = int(input())
a = []
for _ in range(n):
  x, y, r = map(int, input().split())
  a.append((x, y, r))

graph = [[] for _ in range(n)]

for i in range(n):
  for j in range(i + 1, n):
    x1, y1, r1 = a[i]
    x2, y2, r2 = a[j]
    if (x1 - x2) ** 2 + (y1 - y2) ** 2 == (r1 + r2) ** 2:
      graph[i].append(j)
      graph[j].append(i)
col = [-1] * n
for i in range(n):
  if col[i] == -1:
    stack = [i]
    col[i] = 0
    c0, c1 = 1, 0
    f = True
    while stack:
      u = stack.pop()
      for v in graph[u]:
        if col[v] == -1:
          col[v] = col[u] ^ 1
          stack.append(v)
          if col[v]:
            c1 += 1
          else:
            c0 += 1
        else:
          if col[v] == col[u]:
            f = False

    if f and c0 != c1:
      print("YES")
      exit()

print("NO")
