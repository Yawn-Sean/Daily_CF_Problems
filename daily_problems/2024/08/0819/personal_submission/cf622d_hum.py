n = int(input())
res = [0] * (n * 2)

for i in range(n // 2):
  res[i] = i * 2 + 1
  res[n - i - 1] = i * 2 + 1
  res[n + i] = (i + 1) * 2
  res[2 * n - 2 - i] = (i + 1) * 2

for i in range(n * 2):
  if res[i] == 0:
    res[i] = n

print(' '.join(map(str, res)))
