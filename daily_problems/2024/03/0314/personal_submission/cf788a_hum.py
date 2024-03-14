n = int(input())
a = list(map(int, input().split()))
d = [abs(a[i] - a[i + 1]) for i in range(n - 1)]

m = 0
s = 0
res = float('-inf')
t = 1
for v in d:
  s += v * t
  t *= -1
  res = max(res, s - m)
  m = min(m, s)

m = 0
s = 0
t = 1
for v in d[1:]:
  s += v * t
  t *= -1
  res = max(res, s - m)
  m = min(m, s)

print(res)
