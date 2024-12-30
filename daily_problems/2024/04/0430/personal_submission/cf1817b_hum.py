t = int(input())


def solve():
  n, m = map(int, input().split())
  graph = [[] for _ in range(n)]
  for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    graph[a].append(b)
    graph[b].append(a)

  for i in range(n):
    if len(graph[i]) >= 4:

      cur_path = []
      p = [-1] * n
      stack = [i]
      vis = [0] * n
      while stack:
        u = stack.pop()
        if u >= 0:
          cur_path.append(u)
          vis[u] += 1
          stack.append(~u)
          for v in graph[u]:
            if v == p[u]:
              continue
            if v == i:
              cnt = 0
              res = []
              for x in graph[i]:
                if vis[x] == 0:
                  res.append((i, x))
                  cnt += 1
                if cnt == 2:
                  for idx in range(len(cur_path)):
                    res.append((cur_path[idx], cur_path[(idx + 1) % len(cur_path)]))
                  print("YES")
                  print(len(res))
                  for x, y in res:
                    print(x + 1, y + 1)
                  return

            if vis[v] == 0:
              p[v] = u
              stack.append(v)
        else:
          pop = cur_path.pop()
          vis[pop] -= 1
  print("NO")


for _ in range(t):
  solve()
