from collections import deque

n, m, p = map(int, input().split())
s = list(map(int, input().split()))

grid = [list(input()) for _ in range(n)]

que = [deque() for _ in range(p)]

for i in range(n):
  for j in range(m):
    if grid[i][j] != '.' and grid[i][j] != '#':
      que[int(grid[i][j]) - 1].append((i, j))

dis = [[0] * m for _ in range(n)]

while True:
  f = False
  for i in range(p):
    for x, y in que[i]:
      dis[x][y] = 0

    while que[i]:
      f = True
      x, y = que[i][0]
      if dis[x][y] == s[i]:
        break
      x, y = que[i].popleft()

      for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == '.':
          grid[nx][ny] = str(i + 1)
          dis[nx][ny] = dis[x][y] + 1
          que[i].append((nx, ny))

  if not f:
    break

res = [0] * p

for i in range(n):
  for j in range(m):
    if grid[i][j] != '.' and grid[i][j] != '#':
      res[int(grid[i][j]) - 1] += 1

print(*res)
