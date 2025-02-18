n, m = map(int, input().split())
a = []
for _ in range(m):
  a.append(list(map(int, input().split())))

res = list(range(1, m + 1))
for i in range(n - 1):
  tmp = []
  for j in range(m):
    tmp.append((a[j][i] - a[j][-1], j))
  tmp.sort(reverse=True)
  j = -1
  acc = 0
  while j + 1 < m and acc + tmp[j + 1][0] >= 0:
    acc += tmp[j + 1][0]
    j += 1
  if m - (j + 1) < len(res):
    res = [tmp[k][1] + 1 for k in range(j + 1, m)]

print(len(res))
print(*res)
