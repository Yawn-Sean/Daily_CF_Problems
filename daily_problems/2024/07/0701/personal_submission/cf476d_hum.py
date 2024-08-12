n, k = map(int, input().split())

res = []
cur = 1
for _ in range(n):
  res.append((cur * k, (cur + 1) * k, (cur + 2) * k, (cur + 4) * k))
  cur += 6

print(res[-1][-1])
for x in res:
  print(*x)
