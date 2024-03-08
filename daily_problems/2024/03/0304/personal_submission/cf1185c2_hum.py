n, M = map(int, input().split())
a = list(map(int, input().split()))
d = dict()
s = 0
res = []
for x in a:
  can = M - x
  cur = 0
  tmp = 0
  for j in range(100, 0, -1):
    if s - (tmp + d.get(j, 0) * j) <= can:
      if j in d:
        cur += max(0, (s - tmp - can + j - 1) // j)
      break
    else:
      cur += d.get(j, 0)
      tmp += d.get(j, 0) * j

  res.append(cur)
  s += x
  d[x] = d.get(x, 0) + 1
print(*res)
