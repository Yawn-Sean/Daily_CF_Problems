n = int(input())
p = [-1] + list(map(lambda x: int(x) - 1, input().split()))
res = [1] * n
for i in range(1, n):
  res[p[i]] = 0

for i in range(n - 1, 0, -1):
  res[p[i]] += res[i]

res.sort()
print(*res)
