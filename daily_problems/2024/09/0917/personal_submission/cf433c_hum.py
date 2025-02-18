n, m = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))
tmp = [[] for i in range(n)]
for i in range(m):
  if i + 1 < m and a[i] != a[i + 1]:
    tmp[a[i]].append(a[i + 1])
  if i - 1 >= 0 and a[i] != a[i - 1]:
    tmp[a[i]].append(a[i - 1])

old = sum([abs(a[i] - a[i + 1]) for i in range(m - 1)])

res = 0

for i in range(n):
  if tmp[i]:
    tmp[i].sort()
    x = tmp[i][len(tmp[i]) // 2]
    change = 0
    for v in tmp[i]:
      change += abs(i - v) - abs(x - v)

    res = max(res, change)

print(old - res)
