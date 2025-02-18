n, m, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
ans = 0
cnt = 0

acc = [0] * (n + 1)
for i in range(m):
  for j in range(n):
    acc[j + 1] = acc[j] + grid[j][i]

  res = 0
  chosen_idx = 0

  for j in range(n):
    if grid[j][i]:
      v = acc[min(j + k, n)] - acc[j]
      if v > res:
        res = v
        chosen_idx = acc[j]

  ans += res
  cnt += chosen_idx

print(ans, cnt)
