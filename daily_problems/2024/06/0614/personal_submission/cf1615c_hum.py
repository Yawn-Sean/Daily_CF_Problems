from math import inf

t = int(input())
for _ in range(t):
  n = int(input())
  a = input()
  b = input()
  s = 0
  for x, y in zip(a, b):
    if x != y:
      s += 1
  s1 = a.count('1')
  s2 = b.count('1')
  res = inf
  if s1 == s2:
    res = s
  if n - s1 == s2 - 1:
    res = min(res, n - s)
  print(res if res != inf else -1)
