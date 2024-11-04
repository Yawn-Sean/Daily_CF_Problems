import sys

input = lambda: sys.stdin.readline().rstrip()

n, q = map(int, input().split())
rev = 0
d1, d2 = 0, 0
for _ in range(q):
  a = list(map(int, input().split()))
  if len(a) == 1:
    if rev:
      d1 -= 1
      d2 += 1
    else:
      d1 += 1
      d2 -= 1
    rev ^= 1
  else:
    d1 += a[1]
    d2 += a[1]
    rev ^= a[1] % 2

res = [0] * n
for i in range(n):
  if i % 2 == 0:
    res[(i + d1) % n] = i + 1
  else:
    res[(i + d2) % n] = i + 1

print(*res)
