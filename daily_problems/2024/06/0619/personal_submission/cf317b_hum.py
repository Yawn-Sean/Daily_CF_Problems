import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())

base = 75

grid = [[0] * 151 for _ in range(151)]
grid[base][base] = n

dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

while True:
  flag = True
  for i in range(151):
    for j in range(151):
      if grid[i][j] >= 4:
        v, grid[i][j] = divmod(grid[i][j], 4)
        flag = False
        for di, dj in dirs:
          grid[i + di][j + dj] += v

  if flag:
    break

for _ in range(m):
  x, y = map(int, input().split())
  if abs(x) > base or abs(y) > base:
    print(0)
  else:
    print(grid[x + base][y + base])
