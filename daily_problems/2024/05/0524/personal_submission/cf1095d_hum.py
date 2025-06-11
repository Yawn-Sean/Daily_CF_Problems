import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = []
for i in range(n):
  x, y = map(lambda x: int(x) - 1, input().split())
  a.append((x, y))

res = [0]

x, y = a[0]
if a[x][0] == y or a[x][1] == y:
  res.append(x)
  res.append(y)
else:
  res.append(y)
  res.append(x)

for _ in range(n - 3):
  x, y = res[-2], res[-1]
  if y == a[x][0]:
    res.append(a[x][1])
  else:
    res.append(a[x][0])

print(*[x + 1 for x in res])
