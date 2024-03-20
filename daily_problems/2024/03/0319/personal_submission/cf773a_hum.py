t = int(input())
for _ in range(t):
  x, y, p, q = map(int, input().split())
  if p == 0:
    print(0 if x == 0 else -1)
  elif p == q:
    print(0 if x == y else -1)
  else:
    k = max((x + p - 1) // p, (y - x + q - p - 1) // (q - p))
    print(p * k - x + (q - p) * k - (y - x))
