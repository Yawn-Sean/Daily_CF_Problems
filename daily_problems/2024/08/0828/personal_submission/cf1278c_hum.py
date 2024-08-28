from math import inf

t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  diff = 0
  d = dict()
  d[0] = 2 * n
  for i in range(2 * n - 1, n - 1, -1):
    if a[i] == 2:
      diff += 1
    else:
      diff -= 1
    d[diff] = i

  diff = 0
  res = d.get(diff, inf)
  for i in range(n):
    if a[i] == 1:
      diff += 1
    else:
      diff -= 1
    res = min(res, n - i - 1 + d.get(diff, inf) - n)

  print(res)
