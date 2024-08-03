import bisect
import sys

input = lambda: sys.stdin.readline().rstrip()

t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  s = input()
  l = list(map(lambda x: int(x) - 1, input().split()))
  r = list(map(lambda x: int(x) - 1, input().split()))
  _ = int(input())
  qs = list(map(lambda x: int(x) - 1, input().split()))
  res = [c for c in s]
  diff = [0] * (n + 1)
  for x in qs:
    i = bisect.bisect_left(r, x)
    a, b = min(x, r[i] + l[i] - x), max(x, r[i] + l[i] - x)
    diff[a] += 1
    diff[b + 1] -= 1

  for i in range(n):
    diff[i + 1] += diff[i]

  j = 0
  for i in range(n):
    if r[j] < i:
      j += 1
    mid = (r[j] + l[j]) // 2
    if diff[i] % 2 and i <= mid:
      res[i], res[r[j] + l[j] - i] = res[r[j] + l[j] - i], res[i]
  print(''.join(res))
