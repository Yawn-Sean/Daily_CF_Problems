import math

l1, r1, t1 = map(int, input().split())
l2, r2, t2 = map(int, input().split())

g = math.gcd(t1, t2)

if l1 < l2:
  l1, r1, t1, l2, r2, t2 = l2, r2, t2, l1, r1, t1

res = -math.inf

k = (l1 - l2) // g
x = l2 + k * g
y = r2 + k * g

if y >= l1:
  res = max(res, min(r1, y) - max(l1, x) + 1)

x = l2 + (k + 1) * g
y = r2 + (k + 1) * g
if x <= r1:
  res = max(res, min(r1, y) - max(l1, x) + 1)

print(0 if res == -math.inf else res)
