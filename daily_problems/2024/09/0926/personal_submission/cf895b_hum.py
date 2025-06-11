from bisect import bisect_right, bisect_left

n, x, k = map(int, input().split())

a = list(map(int, input().split()))
a.sort()

res = 0
for i in range(n):
  r = a[i] // x * x - (k - 1) * x
  r = min(r, a[i])
  l = a[i] // x * x - k * x + 1
  res += bisect_right(a, r) - bisect_left(a, l)
print(res)
