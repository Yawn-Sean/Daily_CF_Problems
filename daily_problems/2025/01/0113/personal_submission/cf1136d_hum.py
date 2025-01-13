n, m = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))
g = [[] for _ in range(n)]

for _ in range(m):
  u, v = map(lambda x: int(x) - 1, input().split())
  g[u].append(v)

vis = [0] * n
vis[a[-1]] = 1
cnt = 1
for i in range(n - 2, -1, -1):
  v = 0
  for j in g[a[i]]:
    if vis[j]:
      v += 1
  if v < cnt:
    vis[a[i]] = 1
    cnt += 1

print(n - cnt)
