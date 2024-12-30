n, h = map(int, input().split())
a = list(map(int, input().split()))
if n == 2:
  print(0)
  print(1, 1)
  exit()

idx = sorted(range(n), key=lambda k: a[k])

res1 = a[idx[-1]] + a[idx[-2]] - a[idx[0]] - a[idx[1]]

res2 = max(a[idx[-1]] + a[idx[-2]], a[idx[0]] + a[idx[-1]] + h) - min(a[idx[0]] + a[idx[1]] + h, a[idx[1]] + a[idx[2]])

if res1 <= res2:
  print(res1)
  print(*([1] * n))
else:
  print(res2)
  res = [1] * n
  m = a.index(min(a))
  res[m] = 2
  print(*res)
