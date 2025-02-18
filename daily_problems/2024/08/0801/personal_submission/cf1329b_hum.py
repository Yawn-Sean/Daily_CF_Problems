t = int(input())
for _ in range(t):
  d, m = map(int, input().split())
  res = 1
  i = 1
  while i < d.bit_length():
    res = res * ((1 << (i - 1)) + 1) % m
    i += 1
  res = res * (d - (1 << (i - 1)) + 2) % m
  print((res - 1) % m)
