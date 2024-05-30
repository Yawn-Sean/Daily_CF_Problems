from collections import Counter

n, q = map(int, input().split())
l, r = [], []
for _ in range(q):
  x, y = map(lambda x: int(x) - 1, input().split())
  l.append(x)
  r.append(y)

g = [[] for _ in range(n)]
for i in range(n):
  for j in range(q):
    if l[j] <= i <= r[j]:
      g[i].append(j)

res = 0
cnt = Counter()
c = [0] * q
for x in g:
  if x:
    res += 1
  if len(x) == 2:
    cnt[(x[0], x[1])] += 1
  if len(x) == 1:
    c[x[0]] += 1

m = 0

for i in range(q):
  for j in range(i + 1, q):
    m = max(m, res - c[i] - c[j] - cnt[(i, j)])

print(m)
