x = int(input())

res = []

for mi in range(1, 2 * 10 ** 6 + 1):
  a = mi * (mi + 1) * (2 * mi + 1) // 6
  b = mi * (mi + 1) // 2

  if x >= a and (x - a) % b == 0:
    w, h = mi, mi + (x - a) // b
    res.append((w, h))
    if w != h:
      res.append((h, w))

res.sort()
print(len(res))
for x, y in res:
  print(x, y)
