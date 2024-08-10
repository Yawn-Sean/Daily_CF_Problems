import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
grid = [input() for _ in range(n)]


def f(x, y):
  return x * m + y


vis = [None] * (n * m)
sx, sy = 0, 0
for i in range(n):
  for j in range(m):
    if grid[i][j] == 'S':
      sx, sy = i, j
      break

stack = [(sx, sy)]

vis[f(sx, sy)] = (sx, sy)
dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
while stack:
  x, y = stack.pop()
  for dx, dy in dirs:
    nx, ny = x + dx, y + dy
    px, py = nx % n, ny % m
    if grid[px][py] == '#':
      continue
    if vis[f(px, py)]:
      if vis[f(px, py)] != (nx, ny):
        print("Yes")
        exit()
    else:
      vis[f(px, py)] = (nx, ny)
      stack.append((nx, ny))

print("No")
