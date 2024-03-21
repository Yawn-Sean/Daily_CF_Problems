from collections import Counter
from random import getrandbits

n = int(input())
a = []
for _ in range(n):
  x, y = map(int, input().split())
  a.append((x, y))

d = dict()
base = getrandbits(32)
cnt = Counter()
res = 0
for i in range(n):
  x1, y1 = a[i][1], a[i][0]
  for j in range(i):
    x2, y2 = a[j][1], a[j][0]
    res += cnt[(x1 + x2) * base + y1 + y2]
    cnt[(x1 + x2) * base + y1 + y2] += 1

print(res)
