n, k, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
res = 0
s = sum(a)
for j in range(n + 1):
  t = m - j * s
  if t < 0:
    break
  cur = k * j + j
  for i in a:
    d = min(n - j, t // i)
    cur += d
    t -= d * i
  res = max(res, cur)
print(res)
