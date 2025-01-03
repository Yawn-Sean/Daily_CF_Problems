x1, y1, x2, y2, x3, y3 = map(int, input().split())
x1, y1 = sorted([x1, y1])
x2, y2 = sorted([x2, y2])
x3, y3 = sorted([x3, y3])
x = [x1, x2, x3]
y = [y1, y2, y3]
n = max(y)
if n * n != sum([x1 * y1, x2 * y2, x3 * y3]):
  print(-1)
  exit()

print(n)
s = "ABC"
vis = [0] * 3
last = n
for i in range(3):
  if y[i] != n:
    continue
  for j in range(x[i]):
    print(s[i] * y[i])
  vis[i] = 1
  last -= x[i]

for i in range(last):
  for j in range(3):
    if vis[j]:
      continue
    if y[j] == last:
      print(s[j] * x[j], end="")
    else:
      print(s[j] * y[j], end="")
  print()
