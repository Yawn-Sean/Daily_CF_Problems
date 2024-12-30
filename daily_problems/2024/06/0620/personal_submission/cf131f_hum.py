n, m, k = map(int, input().split())
grid = [input() for _ in range(n)]
a = [[0] * m for _ in range(n)]
for i in range(1, n - 1):
  for j in range(1, m - 1):
    if grid[i][j] == '1':
      if grid[i - 1][j] == '1' and grid[i][j - 1] == '1' and grid[i + 1][j] == '1' and grid[i][j + 1] == '1':
        a[i][j] = 1

res = 0
for xl in range(n - 1):
  tmp = [0] * m
  for xr in range(xl + 2, n):
    for i in range(m):
      tmp[i] += a[xr - 1][i]

    l, r = 1, 1
    s = 0
    while l < m - 1:
      while r < m - 1 and s < k:
        s += tmp[r]
        r += 1
      if s >= k:
        res += m - r
      s -= tmp[l]
      l += 1

print(res)
