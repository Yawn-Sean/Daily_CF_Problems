import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = []
res = 0
for _ in range(n):
  x, y = map(int, input().split())
  a.append(x - y)
  res += y * n - x

a.sort(reverse=True)

for i in range(n):
  res += a[i] * (i + 1)

print(res)
