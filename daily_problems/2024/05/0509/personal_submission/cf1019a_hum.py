from math import inf

n, m = map(int, input().split())
t = [[] for _ in range(m)]
a = []
for i in range(n):
  p, c = map(int, input().split())
  t[p - 1].append((c, i))
  a.append((c, p - 1, i))

for i in range(m):
  t[i].sort()

a.sort()

res = inf
for i in range(1, n + 1):
  s = 0
  cnt = len(t[0])
  vis = [False] * n
  for j in range(1, m):
    if len(t[j]) >= i:
      for k in range(len(t[j]) - i + 1):
        s += t[j][k][0]
        vis[t[j][k][1]] = True
        cnt += 1

  if cnt < i:
    for j in range(n):
      if vis[a[j][2]] or a[j][1] == 0:
        continue
      cnt += 1
      s += a[j][0]
      if cnt == i:
        break
  res = min(res, s)

print(res)
