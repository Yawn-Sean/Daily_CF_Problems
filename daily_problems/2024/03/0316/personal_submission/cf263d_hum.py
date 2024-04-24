n, m, k = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
  a, b = map(int, input().split())
  graph[a - 1].append(b - 1)
  graph[b - 1].append(a - 1)

dfn = [-1] * n
cur = 0
dfn[cur] = 0
p = [0] * n
while True:
  for v in graph[cur]:
    if dfn[v] == -1:
      dfn[v] = dfn[cur] + 1
      p[v] = cur
      cur = v
      break
    else:
      if dfn[cur] - dfn[v] >= k:
        print(dfn[cur] - dfn[v] + 1)
        res = [cur + 1]
        while cur != v:
          res.append(p[cur] + 1)
          cur = p[cur]
        print(" ".join(map(str, res)))
        exit()
