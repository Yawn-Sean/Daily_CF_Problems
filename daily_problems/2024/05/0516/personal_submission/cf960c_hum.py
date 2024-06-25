x, d = map(int, input().split())
res = []
cur = 1
for i in range(31, 0, -1):
  while x >= 2 ** i - 1:
    x -= 2 ** i - 1
    res.extend([cur] * i)
    cur += d

print(len(res))
print(*res)
