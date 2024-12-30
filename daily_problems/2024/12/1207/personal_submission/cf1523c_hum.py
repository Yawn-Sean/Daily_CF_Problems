t = int(input())

for _ in range(t):
  n = int(input())
  res = []
  for _ in range(n):
    x = int(input())
    if x == 1:
      res.append(1)
    else:
      while res[-1] != x - 1:
        res.pop()
      res[-1] = x
    print(*res, sep='.')
