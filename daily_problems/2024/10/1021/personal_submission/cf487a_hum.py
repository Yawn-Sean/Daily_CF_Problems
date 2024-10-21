h1, a1, d1 = map(int, input().split())

h2, a2, d2 = map(int, input().split())

h, a, d = map(int, input().split())

res = 10 ** 10
for i in range(201):
  for j in range(101):
    if a1 + i - d2 <= 0:
      continue
    x = max(0, a1 + i - d2)
    y = max(0, a2 - d1 - j)
    t1 = (h2 + x - 1) // x
    need = y * t1 + 1 - h1
    cur = i * a + j * d + max(0, need) * h

    res = min(res, cur)

print(res)
