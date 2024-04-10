from math import inf

n = int(input())
a = list(map(int, input().split()))
a.sort()
cnt = 0
m = inf
for i in range(2 * n - 1):
  if a[i] < 0:
    cnt += 1
    a[i] = -a[i]

  m = min(m, abs(a[i]))

if cnt % 2 == 0 or n % 2:
  print(sum(a))
else:
  print(sum(a) - 2 * m)
