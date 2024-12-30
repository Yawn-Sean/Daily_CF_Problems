import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):

  n, x = map(int, input().split())
  a = list(map(int, input().split()))
  res = sum(abs(a[i] - a[i + 1]) for i in range(n - 1))

  res1 = min(abs(a[0] - 1), abs(a[-1] - 1))
  res1 = min(res1, 2 * (min(a) - 1))

  m = max(a)

  if x <= m:
    print(res + res1)
  else:
    res2 = min(abs(a[0] - x), abs(a[-1] - x))
    res2 = min(res2, 2 * (x - m))
    print(res + res1 + res2)
