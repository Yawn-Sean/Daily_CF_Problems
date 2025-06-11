from math import comb

n, k = map(int, input().split())
a = [1, 1, 2, 9]
b = [0, 2, 3, 4]
res = 0
for i in range(k):
  res += comb(n, b[i]) * a[i]

print(res)
