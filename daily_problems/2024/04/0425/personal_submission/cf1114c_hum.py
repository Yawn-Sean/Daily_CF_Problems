from math import inf

n, b = map(int, input().split())


def f(p, c):
  res = 0
  t = n
  while p <= t:
    res += t // p
    t //= p
  return res // c


res = inf
i = 2
while i * i <= b:
  cnt = 0
  while b % i == 0:
    cnt += 1
    b //= i
  if cnt:
    res = min(res, f(i, cnt))
  i += 1

if b > 1:
  res = min(res, f(b, 1))

print(res)
