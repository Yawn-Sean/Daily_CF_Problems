t = int(input())
outs = []

for _ in range(t):
  n, m = list(map(int, input().split()))
  grid = [[int(x) for x in input()] for _ in range(n)]

  ans = n * m
  cnt = [0] * m
  calc = [0] * m

  for i in range(n - 4):
    for j in range(m):
      cnt[j] = 0

    for j in range(i + 1, i + 4):
      for k in range(m):
        cnt[k] += grid[j][k]

    for j in range(i + 4, n):
      for k in range(m):
        calc[k] = cnt[k]

      for k in range(1, m - 1):
        calc[k] += 2 - grid[i][k] - grid[j][k]

      for k in range(1, m):
        calc[k] += calc[k - 1]

      cur = n * m
      for k in range(m - 1, 2, -1):
        cur = min(cur, calc[k - 1] + j - i - 1 - cnt[k])
        ans = min(ans, cur - calc[k - 3] + j - i - 1 - cnt[k - 3])

      for k in range(m):
        cnt[k] += grid[j][k]

  outs.append(ans)

print('\n'.join(map(str, outs)))
