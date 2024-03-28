n, u = map(int, input().split())
a = list(map(int, input().split()))

k = 1
res = -1

for i in range(n - 1):
  j = i + 1
  while k + 1 < n and a[k + 1] - a[i] <= u:
    k += 1
  if k - i >= 2:
    res = max(res, (a[k] - a[j]) / (a[k] - a[i]))

print(res)
