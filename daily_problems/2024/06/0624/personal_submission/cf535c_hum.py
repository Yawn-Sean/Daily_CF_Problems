import sys

input = lambda: sys.stdin.readline().rstrip()
a, b, n = map(int, input().split())
s = [0]
for i in range(1, 1000005):
  x = a + (i - 1) * b
  s.append(s[-1] + x)
  if x > 10 ** 6 + 5:
    break

for _ in range(n):
  ol, t, m = map(int, input().split())
  if ol >= len(s) or s[ol] - s[ol - 1] > t:
    print(-1)
    continue
  r = (t - a) // b + 1
  l = ol
  while l < r:
    mid = l + r + 1 >> 1
    if s[mid] - s[ol - 1] <= t * m:
      l = mid
    else:
      r = mid - 1
  print(l)
