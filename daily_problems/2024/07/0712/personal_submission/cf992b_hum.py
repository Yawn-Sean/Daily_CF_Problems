from math import gcd

l, r, x, y = map(int, input().split())
if y % x != 0:
  print(0)
  exit()

res = 0

k = y // x
i = (l + x - 1) // x
while i * i <= k and i * x <= r:
  if k % i == 0:
    j = k // i
    if l <= j * x <= r and gcd(i, j) == 1:
      if i != j:
        res += 2
      else:
        res += 1
  i += 1

print(res)
