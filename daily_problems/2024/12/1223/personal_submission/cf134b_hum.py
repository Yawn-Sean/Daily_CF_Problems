from math import inf

n = int(input())


def f(a, b):
  if b == 0:
    return inf
  if b == 1:
    return a - 1
  return f(b, a % b) + a // b


res = inf
for i in range(1, n + 1):
  res = min(res, f(n, i))

print(res)
