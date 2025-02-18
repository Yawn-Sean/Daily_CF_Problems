n = int(input())
d1, d2 = 2, 1
res = 0

while d1 <= n:
  d1, d2 = d1 + d2, d1
  res += 1

print(res)
