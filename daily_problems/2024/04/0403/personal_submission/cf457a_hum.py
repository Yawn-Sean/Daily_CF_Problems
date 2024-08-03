from math import sqrt

a = input()
b = input()
n = max(len(a), len(b))
a = a.zfill(n)
b = b.zfill(n)

x, y = 0, 0
for i in range(n):
  x, y = x + y, x + int(a[i]) - int(b[i])
  if x > 1:
    exit(print(">"))
  if x < -1:
    exit(print("<"))

if x == 0 and y == 0:
  print("=")
else:
  if x * (sqrt(5) + 1) / 2 + y > 0:
    print(">")
  else:
    print("<")
