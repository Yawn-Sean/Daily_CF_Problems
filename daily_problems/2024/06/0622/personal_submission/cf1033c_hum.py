n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
pos = [0] * n
for i in range(n):
  pos[a[i]] = i

graph = [[] for i in range(n)]
for i in range(n):
  x = i % (a[i] + 1)
  for j in range(x, n, a[i] + 1):
    if a[j] > a[i]:
      graph[j].append(i)

res = ['C'] * n
for i in range(n - 1, -1, -1):
  p = pos[i]
  if res[p] == 'C':
    res[p] = 'B'
    for v in graph[p]:
      if res[v] == 'C':
        res[v] = 'A'

print(''.join(res))
