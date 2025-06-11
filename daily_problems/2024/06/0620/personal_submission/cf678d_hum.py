a, b, n, x = map(int, input().split())
mod = 10 ** 9 + 7

if a == 1:
  print((x + b * n) % mod)
else:
  print((pow(a, n, mod) * x + b * (pow(a, n, mod) - 1) * pow(a - 1, -1, mod)) % mod)
