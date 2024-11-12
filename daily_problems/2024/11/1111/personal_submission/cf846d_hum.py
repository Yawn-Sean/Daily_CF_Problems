from math import inf

n, m, k, q = map(int, input().split())
grid = []
for i in range(n):
  p = [inf] * m
  grid.append(p)
for j in range(q):
  a, b, c = map(int, input().split())
  grid[a - 1][b - 1] = c

q = []
for i in range(n):
  p = []
  for j in range(m - k + 1):
    p.append(max(grid[i][j:j + k]))
  q.append(p)

res = inf
for i in range(m - k + 1):
  for j in range(n - k + 1):
    w = 0
    for l in range(k):
      w = max(w, q[j + l][i])
    res = min(res, w)

if res == inf:
  print(-1)
else:
  print(res)
