n, m = map(int, input().split())
res = n + 1

for _ in range(m):
  l, r = map(int, input().split())
  res = min(res, r - l + 1)

print(res)
for i in range(n):
  print(i % res, end=' ')
