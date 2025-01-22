a = list(map(int, input().split()))
a.sort()
if a[0] % 2 == a[1] % 2:
  print(a[1])
else:
  print(a[2])
