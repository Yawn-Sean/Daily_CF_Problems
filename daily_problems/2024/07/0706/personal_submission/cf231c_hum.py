from itertools import accumulate

n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
s = list(accumulate(a, initial=0))
l = 0
res = 1
v = a[0]
for i in range(1, n):
  while (i - l + 1) * a[i] - (s[i + 1] - s[l]) > k:
    l += 1
  if i - l + 1 > res:
    res = i - l + 1
    v = a[i]

print(res, v)
