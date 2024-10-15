import sys

input = lambda: sys.stdin.readline().rstrip()
n, q, c = map(int, input().split())
m = 101
grid = [[[0] * (m + 1) for _ in range(m + 1)] for _ in range(c + 1)]

for _ in range(n):
  x, y, s = map(int, input().split())
  for i in range(c + 1):
    grid[i][x][y] += (s + i) % (c + 1)

for i in range(m + 1):
  for j in range(m):
    for k in range(c + 1):
      grid[k][i][j + 1] += grid[k][i][j]

for i in range(m):
  for j in range(m + 1):
    for k in range(c + 1):
      grid[k][i + 1][j] += grid[k][i][j]

for _ in range(q):
  t, x1, y1, x2, y2 = map(int, input().split())
  t %= c + 1
  print(grid[t][x2][y2] - grid[t][x1 - 1][y2] - grid[t][x2][y1 - 1] + grid[t][x1 - 1][y1 - 1])
