import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
x = (n - 1) // 2
mi, ma = x * (x + 1) + (n // 2 if n % 2 == 0 else 0), n * (n - 1) // 2

res = 0
for _ in range(m):
  x, d = map(int, input().split())
  res += x * n
  if d >= 0:
    res += d * ma
  else:
    res += d * mi

print(res / n)
