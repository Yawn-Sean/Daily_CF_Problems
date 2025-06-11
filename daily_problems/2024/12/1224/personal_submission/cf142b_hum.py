n, m = map(int, input().split())

if min(n, m) == 1:
  print(n * m)
elif min(n, m) == 2:
  v = max(n, m)
  print(v // 4 * 4 + min(v % 4, 2) * 2)
else:
  print((n * m + 1) // 2)
