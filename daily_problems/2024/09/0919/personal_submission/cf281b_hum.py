from math import inf

x, y, n = map(int, input().split())

res1, res2 = -1, -1
for b in range(1, n + 1):
  a = b * x // y
  if res1 == -1:
    res1, res2 = a, b

  nx, ny = abs(x * b - y * a), y * b
  ox, oy = abs(x * res2 - y * res1), y * res2
  if nx * oy < ox * ny:
    res1, res2 = a, b

  a += 1
  nx, ny = abs(x * b - y * a), y * b
  ox, oy = abs(x * res2 - y * res1), y * res2
  if nx * oy < ox * ny:
    res1, res2 = a, b

print(str(res1) + "/" + str(res2))
