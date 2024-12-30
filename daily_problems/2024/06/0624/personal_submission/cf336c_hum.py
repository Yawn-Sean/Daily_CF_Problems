n = int(input())
a = list(map(int, input().split()))
for i in range(30, -1, -1):
  x = 1 << i
  y = x - 1
  res = []
  for v in a:
    if v & x:
      res.append(v)
      y &= v
  if y == 0:
    print(len(res))
    print(*res)
    exit()
