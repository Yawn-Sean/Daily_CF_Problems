from math import atan2, pi

n = int(input())

tmp = []
for _ in range(n):
  x, y = map(int, input().split())
  tmp.append(atan2(y, x))

tmp.sort()
res = 0

for i in range(1, n):
  res = max(res, tmp[i] - tmp[i - 1])

print(min(2 * pi - res, tmp[-1] - tmp[0]) / pi * 180)
