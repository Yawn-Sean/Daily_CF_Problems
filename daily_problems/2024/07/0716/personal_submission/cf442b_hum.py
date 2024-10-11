n = int(input())
a = list(map(float, input().split()))
a.sort(reverse=True)
p0, p1 = 1, 0
res = 0
for x in a:
  if p0 < p1:
    break
  p1 = p0 * x + p1 * (1 - x)
  p0 = p0 * (1 - x)

  res = max(res, p1)

print(res)
