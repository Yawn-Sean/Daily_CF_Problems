import sys

input = lambda: sys.stdin.readline().rstrip()

from functools import reduce
from operator import xor

t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  c = list(map(int, input().split()))
  xor_sum = reduce(xor, c)

  graph = [[] for _ in range(n)]
  for _ in range(n - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    graph[a].append(b)
    graph[b].append(a)
  if xor_sum == 0:
    print("YES")
  elif k == 2:
    print("NO")
  else:
    stack = [0]
    dfs_order = []
    p = [-1] * n
    while stack:
      u = stack.pop()
      dfs_order.append(u)
      for v in graph[u]:
        if p[u] == v:
          continue
        p[v] = u
        stack.append(v)

    cnt = 0
    for u in reversed(dfs_order):
      if c[u] == xor_sum:
        cnt += 1
      elif u:
        c[p[u]] ^= c[u]

    if cnt >= 2:
      print("YES")
    else:
      print("NO")
