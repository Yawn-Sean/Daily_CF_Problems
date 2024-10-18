import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
a = []
for _ in range(m):
  x, y = map(int, input().split())
  a.append(y)

a.sort(reverse=True)


def f(x):
  if x % 2 == 1:
    return x * (x - 1) // 2 + 1
  else:
    return x * (x - 1) // 2 + (x - 2) // 2 + 1


res = 0
for i in range(1, m + 1):
  if f(i) > n:
    break
  res += a[i - 1]

print(res)
