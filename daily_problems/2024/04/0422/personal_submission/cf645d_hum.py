import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
a = []
for _ in range(m):
  u, v = map(lambda x: int(x) - 1, input().split())
  a.append((u, v))


def check(mid):
  graph = [[] for _ in range(n)]
  dep = [0] * n
  for i in range(mid + 1):
    graph[a[i][0]].append(a[i][1])
    dep[a[i][1]] += 1

  q = []
  for i in range(n):
    if dep[i] == 0:
      q.append(i)
  if len(q) != 1:
    return False
  cnt = 0
  while q:
    if len(q) != 1:
      return False
    u = q.pop()
    cnt += 1
    for v in graph[u]:
      dep[v] -= 1
      if dep[v] == 0:
        q.append(v)

  return cnt == n


l = 0
r = m - 1
while l < r:
  mid = l + r >> 1
  if check(mid):
    r = mid
  else:
    l = mid + 1
if check(l):
  print(l + 1)
else:
  print(-1)
