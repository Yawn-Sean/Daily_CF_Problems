n, m = map(int, input().split())
v = list(map(int, input().split()))
res = 0
for _ in range(m):
  a, b, c = map(int, input().split())
  res = max(res, (v[a - 1] + v[b - 1]) / c)

print(res)
