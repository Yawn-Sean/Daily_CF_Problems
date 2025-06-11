n, m, k, r, c = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())

mod = 10 ** 9 + 7
res = pow(k, n * m - r * c, mod)
if x1 == x2 and y1 == y2:
  res = pow(k, n * m, mod)
print(res)
