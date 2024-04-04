from collections import defaultdict
from math import gcd

t = int(input())
for _ in range(t):
  n = int(input())
  m = defaultdict(int)
  res = 0
  for _ in range(n):
    x, y, u, v = map(int, input().split())
    x, y = x - u, y - v
    g = gcd(x, y)
    x //= g
    y //= g
    res += m[(-x, -y)]
    m[(x, y)] += 1
  print(res)
