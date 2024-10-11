n, k, x = map(int, input().split())
a = list(map(int, input().split()))

v = pow(x, k)

pre = a[:]
suf = a[:]

for i in range(1, n):
  pre[i] |= pre[i - 1]

for i in range(n - 2, -1, -1):
  suf[i] |= suf[i + 1]

res = 0
for i in range(n):
  cur = v * a[i]
  if i >= 1:
    cur = cur | pre[i - 1]
  if i + 1 < n:
    cur = cur | suf[i + 1]
  res = max(res, cur)

print(res)
