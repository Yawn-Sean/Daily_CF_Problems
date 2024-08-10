import sys

input = lambda: sys.stdin.readline().rstrip()
n, m, h, t = map(int, input().split())
edges = []
graph = [set() for _ in range(n)]
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  graph[a].add(b)
  graph[b].add(a)
  edges.append((a, b))


def solve(u, v):
  len_u, len_v = len(graph[u]) - 1, len(graph[v]) - 1
  if len_u < h or len_v < t:
    return False

  if len_u >= h + t:
    print("YES")
    print(u + 1, v + 1)
    res_v = []
    s = graph[u]
    s.discard(v)
    for x in graph[v]:
      if x == u:
        continue
      res_v.append(x)
      s.discard(x)
      if len(res_v) >= t:
        break
    res_u = []
    for x in graph[u]:
      res_u.append(x)
      if len(res_u) >= h:
        break
    print(' '.join(str(i + 1) for i in res_u))
    print(' '.join(str(i + 1) for i in res_v))
    return True

  elif len_v >= h + t:
    print("YES")
    print(u + 1, v + 1)
    res_u = []
    s = graph[v]
    s.discard(u)
    for x in graph[u]:
      if x == v:
        continue
      res_u.append(x)
      s.discard(x)
      if len(res_u) >= h:
        break
    res_v = []
    for x in graph[v]:
      res_v.append(x)
      if len(res_v) >= t:
        break
    print(' '.join(str(i + 1) for i in res_u))
    print(' '.join(str(i + 1) for i in res_v))
    return True
  else:
    uni = graph[u] & graph[v]
    if len_u + len_v - len(uni) >= h + t:
      graph[u].discard(v)
      graph[v].discard(u)
      res_u = []
      for x in graph[u] - uni:
        res_u.append(x)
        if len(res_u) >= h:
          break
      res_v = []
      for x in graph[v] - uni:
        res_v.append(x)
        if len(res_v) >= t:
          break

      for x in uni:
        if len(res_u) < h:
          res_u.append(x)
        elif len(res_v) < t:
          res_v.append(x)
      print("YES")
      print(u + 1, v + 1)
      print(' '.join(str(i + 1) for i in res_u))
      print(' '.join(str(i + 1) for i in res_v))
      return True


for u, v in edges:
  if solve(u, v):
    exit()
  if solve(v, u):
    exit()
print("NO")
