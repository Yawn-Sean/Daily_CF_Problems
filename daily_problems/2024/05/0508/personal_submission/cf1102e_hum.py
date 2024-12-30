n = int(input())
a = list(map(int, input().split()))

d = dict()
for i in range(n):
  d[a[i]] = i
m = 0

res = 0
for i in range(n):
  if i > m:
    res += 1
  m = max(m, d[a[i]])

print(pow(2, res, 998244353))
