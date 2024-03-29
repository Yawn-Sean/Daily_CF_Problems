import math

n = int(input())
a = list(map(int, input().split()))
cnt = a.count(1)
res = 2 * n
if cnt > 0:
  res = n - cnt

for i in range(n):
  cur = a[i]
  for j in range(i + 1, n):
    cur = math.gcd(cur, a[j])
    if cur == 1:
      res = min(res, j - i + n - 1)
      break

print(-1 if res == 2 * n else res)
