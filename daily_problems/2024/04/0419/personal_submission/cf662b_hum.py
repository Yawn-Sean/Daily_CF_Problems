import sys
from math import inf

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
  a, b, c = input().split()
  a = int(a) - 1
  b = int(b) - 1
  c = 1 if c == 'R' else 0
  graph[a].append((b, c))
  graph[b].append((a, c))

ans = inf
chosen = []


def solve(t):
  global chosen
  global ans
  flips = [-1] * n
  for i in range(n):
    if flips[i] == -1:
      flips[i] = 0
      stack = [i]
      block = []
      while stack:
        u = stack.pop()
        block.append(u)
        for v, c in graph[u]:
          if c == t:
            if flips[v] == -1:
              flips[v] = flips[u]
              stack.append(v)
            elif flips[v] != flips[u]:
              return inf
          else:
            if flips[v] == -1:
              flips[v] = 1 - flips[u]
              stack.append(v)
            elif flips[v] == flips[u]:
              return inf
      if (tmp := sum(flips[x] for x in block)) > len(block) - tmp:
        for x in block:
          flips[x] ^= 1

  cur = sum(flips)
  if ans == inf or len(chosen) > cur:
    ans = cur
    chosen = [i for i in range(n) if flips[i]]
  return cur


ans = min(ans, solve(0))
ans = min(ans, solve(1))
if ans != inf:
  print(ans)
  print(' '.join(str(x + 1) for x in chosen))
else:
  print(-1)
