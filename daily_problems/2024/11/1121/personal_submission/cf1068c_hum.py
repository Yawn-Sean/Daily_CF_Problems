n, m = map(int, input().split())
res = [[] for _ in range(n + 1)]

for i in range(1, n + 1):
  res[i].append((i, i))

for i in range(m):
  x, y = map(int, input().split())
  res[x].append((n + 1 + i, x))
  res[y].append((n + 1 + i, y))

for i in range(1, n + 1):
  print(len(res[i]))
  for v in res[i]:
    print(*v)
