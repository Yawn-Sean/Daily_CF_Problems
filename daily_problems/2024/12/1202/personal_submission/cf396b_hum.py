from math import gcd

t = int(input())


def f(x):
  for i in range(2, int(x ** 0.5) + 1):
    if x % i == 0:
      return False
  return True


for _ in range(t):
  n = int(input())
  v = n
  while not f(v):
    v -= 1
  u = n + 1
  while not f(u):
    u += 1

  a = u * v - 2 * u + 2 * (n - v + 1)
  b = 2 * u * v
  g = gcd(a, b)
  print(f'{a // g}/{b // g}')
