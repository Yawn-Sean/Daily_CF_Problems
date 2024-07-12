import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
t = [[i] for i in range(n)]
f = [i for i in range(n)]
for _ in range(n - 1):
  a, b = map(lambda x: int(x) - 1, input().split())
  a, b = f[a], f[b]
  if len(t[a]) >= len(t[b]):
    for v in t[b]:
      f[v] = a
    t[a].extend(t[b])
    t[b].clear()
  else:
    for v in t[a]:
      f[v] = b
    t[b].extend(t[a])
    t[a].clear()

for i in t:
  for v in i:
    print(v + 1, end=' ')
