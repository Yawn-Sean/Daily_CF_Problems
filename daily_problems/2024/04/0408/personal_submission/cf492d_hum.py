import sys
from math import gcd

input = lambda: sys.stdin.readline().rstrip()

n, x, y = map(int, input().split())

g = gcd(x, y)
x //= g
y //= g
for _ in range(n):
  a = int(input())
  l, r = 1, 10 ** 15
  while l < r:
    mid = l + r >> 1
    if mid // x + mid // y >= a:
      r = mid
    else:
      l = mid + 1

  if l % x == 0 and l % y == 0:
    print("Both")
  elif l % x == 0:
    print("Vova")
  else:
    print("Vanya")
