n, k = map(int, input().split())
a = list(map(int, input().split()))

mi, ma = min(a), max(a)
acc = sum(a)

l, r = (acc + n - 1) // n, ma
while l < r:
  mid = l + r >> 1
  t = 0
  for x in a:
    if x > mid:
      t += x - mid
  if t > k:
    l = mid + 1
  else:
    r = mid

res1 = l

l, r = mi, acc // n
while l < r:
  mid = l + r + 1 >> 1
  t = 0
  for x in a:
    if x < mid:
      t += mid - x
  if t > k:
    r = mid - 1
  else:
    l = mid
res2 = l

print(res1 - res2)
