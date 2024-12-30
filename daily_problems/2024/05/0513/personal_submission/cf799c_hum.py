n, c, d = map(int, input().split())

cs, ds = [], []
for _ in range(n):
  x, y, t = input().split()
  x = int(x)
  y = int(y)
  if t == 'C':
    cs.append((y, x))
  else:
    ds.append((y, x))

cs.sort()
ds.sort()


def f(arr, m):
  pre_max = [0] * (len(arr) + 1)
  ans = 0
  for i, (c, b) in enumerate(arr):
    if c >= m:
      break
    j = bisect_left(arr, (m - c + 1,), hi=i)
    if j > 0:
      ans = max(ans, b + pre_max[j])
    pre_max[i + 1] = max(pre_max[i], b)
  return ans


ans1 = f(cs, c)
ans2 = f(ds, d)
res1 = max((y for x, y in cs if x <= c), default=0)
res2 = max((y for x, y in ds if x <= d), default=0)
ans3 = res1 + res2 if res1 and res2 else 0
print(max(ans1, ans2, ans3))
