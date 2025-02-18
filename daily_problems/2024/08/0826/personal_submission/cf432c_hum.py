from math import isqrt

n = int(input())
a = list(map(int, input().split()))
prime = [True] * (n + 1)

prime[1] = False
for i in range(2, isqrt(n) + 1):
  if prime[i]:
    for j in range(i * i, n + 1, i):
      prime[j] = False

res = []
pos = {a[i]: i + 1 for i in range(n)}

for i in range(1, n + 1):
  cur = pos[i]
  while cur > i:
    tmp = i
    while not prime[cur - tmp + 1]:
      tmp += 1
    res.append((tmp, cur))
    pos[a[tmp - 1]] = cur
    a[tmp - 1], a[cur - 1] = a[cur - 1], a[tmp - 1]
    cur = tmp

print(len(res))
for x, y in res:
  print(x, y)
