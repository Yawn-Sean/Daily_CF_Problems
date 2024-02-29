import math

t = int(input())
for _ in range(t):
  r, b, k = map(int, input().split())
  if r > b:
    b, r = r, b
  g = math.gcd(b, r)
  b //= g
  r //= g
  if (b - 1 + r - 1) // r < k:
    print("OBEY")
  else:
    print("REBEL")
