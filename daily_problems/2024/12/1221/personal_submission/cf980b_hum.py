n, k = map(int, input().split())

print('YES')

res = [['.'] * n for _ in range(4)]
if k % 2 == 0:
  for i in range(k // 2):
    res[1][i + 1] = '#'
    res[2][i + 1] = '#'
else:
  v = k // 2
  res[1][n // 2] = '#'

  for i in range(1, 3):
    for j in range(1, n // 2):
      if v:
        v -= 1
        res[i][j] = '#'
        res[i][n - j - 1] = '#'

print('\n'.join(''.join(x) for x in res))
