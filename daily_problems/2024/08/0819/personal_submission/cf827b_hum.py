n, k = map(int, input().split())

x, y = divmod(n - 1, k)
print(2 * x + min(y, 2))

for i in range(2, k + 2):
  print(1, i)

for i in range(k + 2, n + 1):
  print(i, i - k)
