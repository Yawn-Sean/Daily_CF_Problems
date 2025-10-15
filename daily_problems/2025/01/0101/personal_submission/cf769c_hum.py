n, m, k = map(int, input().split())

sx, sy = -1, -1
grid = [[1] * m for _ in range(n)]

for i in range(n):
  s = input()
  for j in range(m):
    if s[j] == 'X':
      sx, sy = i, j
    elif s[j] == '*':
      grid[i][j] = 0

if k % 2:
  print('IMPOSSIBLE')
else:
  dis = [[-1] * m for _ in range(n)]

  que = [0] * (n * m)
  que[0] = sx * m + sy
  l, r = 0, 1

  dis[sx][sy] = 0

  dlru = 'DLRU'
  dirs = [(1, 0), (0, -1), (0, 1), (-1, 0)]
  while l < r:
    x, y = divmod(que[l], m)
    l += 1
    for dx, dy in dirs:
      nx = x + dx
      ny = y + dy
      if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] and dis[nx][ny] == -1:
        dis[nx][ny] = dis[x][y] + 1
        que[r] = nx * m + ny
        r += 1

  res = []
  while k:
    for i in range(4):
      dx, dy = dirs[i]
      nx = sx + dx
      ny = sy + dy
      if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] and dis[nx][ny] <= k - 1:
        sx = nx
        sy = ny
        res.append(dlru[i])
        break
    else:
      exit(print('IMPOSSIBLE'))
    k -= 1

  print(''.join(res))
