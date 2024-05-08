from math import isqrt

c, hr, hb, wr, wb = map(int, input().split())
res = 0
base = isqrt(c)
for i in range(base + 5):
  if wr * i > c:
    break
  res = max(res, i * hr + (c - i * wr) // wb * hb)

for i in range(base + 5):
  if wb * i > c:
    break
  res = max(res, i * hb + (c - i * wb) // wr * hr)

print(res)
