from math import isqrt

n = int(input())
a = list(map(int, input().split()))

q = int(input())
lim = isqrt(n)

res = [0] * q
q_tmp = [[] for _ in range(lim)]
for i in range(q):
  st, k = map(int, input().split())
  st -= 1
  if k >= lim:
    for j in range(st, n, k):
      res[i] += a[j]
  else:
    q_tmp[k].append((i, st))

acc = [0] * n
for i in range(1, lim):
  if q_tmp[i]:
    for j in range(n - 1, -1, -1):
      if j + i < n:
        acc[j] = acc[j + i] + a[j]
      else:
        acc[j] = a[j]

    for i, st in q_tmp[i]:
      res[i] = acc[st]

print(*res, sep='\n')
