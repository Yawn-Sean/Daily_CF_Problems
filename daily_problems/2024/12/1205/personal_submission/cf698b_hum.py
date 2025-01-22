n = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))

rt = -1
for i in range(n):
  if p[i] == i:
    rt = i

res = 0
vis = [-1] * n
for i in range(n):
  if vis[i] == -1:
    u = i
    while vis[u] == -1:
      vis[u] = i
      u = p[u]

    if vis[u] == i and u != rt:
      res += 1
      if rt >= 0:
        p[u] = rt
      else:
        p[u] = u
        rt = u

print(res)
print(*[p[i] + 1 for i in range(n)])
