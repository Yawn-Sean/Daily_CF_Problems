n, k = map(int, input().split())
grid = [input() for _ in range(n)]

cnt = 0

diff = [[0] * (n + 1) for _ in range(n + 1)]


def add(x1, y1, x2, y2):
  diff[x1][y1] += 1
  diff[x2 + 1][y1] -= 1
  diff[x1][y2 + 1] -= 1
  diff[x2 + 1][y2 + 1] += 1


for i in range(n):
  l = n
  r = -1
  for j in range(n):
    if grid[i][j] == 'B':
      l = min(l, j)
      r = max(r, j)
  if l > r:
    cnt += 1
  elif l + k - 1 >= r:
    x1 = max(0, i - k + 1)
    y1 = max(0, r - k + 1)
    x2 = i
    y2 = l
    add(x1, y1, x2, y2)

for j in range(n):
  l = n
  r = -1
  for i in range(n):
    if grid[i][j] == 'B':
      l = min(l, i)
      r = max(r, i)
  if l > r:
    cnt += 1
  elif l + k - 1 >= r:
    x1 = max(0, r - k + 1)
    y1 = max(0, j - k + 1)
    x2 = l
    y2 = j
    add(x1, y1, x2, y2)

for i in range(n):
  for j in range(n + 1):
    diff[i + 1][j] += diff[i][j]

for i in range(n + 1):
  for j in range(n):
    diff[i][j + 1] += diff[i][j]

print(max(max(x) for x in diff) + cnt)
