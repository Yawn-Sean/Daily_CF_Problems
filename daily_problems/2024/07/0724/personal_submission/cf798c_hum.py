from math import gcd

n = int(input())
a = list(map(int, input().split()))
if gcd(*a) > 1:
  print("YES")
  print(0)
else:
  res = 0
  i, j = 0, 0
  while i < n:
    if a[i] % 2 == 0:
      i += 1
      continue
    j = i
    while j + 1 < n and a[j + 1] % 2 == 1:
      j += 1
    l = j - i + 1

    if l % 2:
      res += l // 2 + 2
    else:
      res += l // 2
    i = j + 1
  print("YES")
  print(res)
