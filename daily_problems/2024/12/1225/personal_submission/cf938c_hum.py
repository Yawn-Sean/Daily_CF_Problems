t = int(input())
for _ in range(t):
  x = int(input())
  if x == 0:
    print(1, 1)
    continue
  for i in range(1, x):
    if i * i >= x:
      print(-1)
      break
    if x % i == 0:
      n = (x // i + i) // 2
      m = (x // i + i) // (x // i - i)
      if n * n - (n // m) * (n // m) == x:
        print(n, m)
        break
  else:
    print(-1)
