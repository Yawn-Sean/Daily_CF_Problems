n, d, s = map(int, input().split())

n //= s
d //= s

if n <= d + 1:
  print(n * s)
else:
  n = min(n, 2 * d)
  for i in range(2, 10 ** 6 + 1):
    if n % i == 0 and n - n // i <= d:
      exit(print(n * s))
  print((n - 1) * s)
