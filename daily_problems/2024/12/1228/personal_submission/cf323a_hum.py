n = int(input())
if n % 2:
  print(-1)
else:
  for i in range(n):
    if i: print()
    for j in range(n):
      print(''.join('wb'[(i & 1) ^ (j >> 1 & 1) ^ (k >> 1 & 1)] for k in range(n)))
