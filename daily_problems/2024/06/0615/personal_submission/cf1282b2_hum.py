t = int(input())
for _ in range(t):
  n, p, k = map(int, input().split())
  a = list(map(int, input().split()))
  a.sort()
  res = 0
  for i in range(k):
    s = 0
    if p >= 0:
      res = max(res, i)
    else:
      break
    for j in range(k - 1 + i, n, k):
      s += a[j]
      if s <= p:
        res = max(res, j + 1)
      else:
        break
    p -= a[i]

  print(res)
