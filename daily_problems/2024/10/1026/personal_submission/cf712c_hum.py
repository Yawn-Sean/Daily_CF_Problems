x, y = map(int, input().split())

a = [y, y, y]
t = [x, x, x]

res = 0
while a[0] < t[0] or a[1] < t[1] or a[2] < t[2]:
  a[0] = a[1] + a[2] - 1
  a.sort()
  res += 1

print(res)
