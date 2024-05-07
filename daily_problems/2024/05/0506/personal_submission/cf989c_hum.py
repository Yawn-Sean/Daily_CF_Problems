a = list(map(int, input().split()))

n = 50
s = 'ABCD'

res = [[''] * n for _ in range(n)]

for i in range(n):
  for j in range(n):
    res[i][j] = s[i // 25 * 2 + j // 25]

for i in range(4):
  a[i] -= 1
  dx, dy = divmod((i + 1) % 4, 2)
  for x in range(1, 25, 2):
    for y in range(1, 25, 2):
      if a[i]:
        res[x + dx * 25][y + dy * 25] = s[i]
        a[i] -= 1

print(n, n)
for x in res:
  print(''.join(x))
