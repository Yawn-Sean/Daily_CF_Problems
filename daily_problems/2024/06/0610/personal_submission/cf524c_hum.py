from collections import defaultdict
from math import inf

n, k = map(int, input().split())
a = list(map(int, input().split()))
qs = []
q = int(input())
for _ in range(q):
  qs.append(int(input()))
m = max(qs)

dic = {}

dic[0] = 0
res = defaultdict(lambda: inf)
for i in range(n):
  for j in range(k + 1):
    for q in qs:
      need = q - a[i] * j
      if need >= 0 and need in dic:
        res[q] = min(res[q], dic[need] + j)

  for j in range(1, k + 1):
    if a[i] * j <= m:
      if a[i] * j in dic:
        dic[a[i] * j] = min(dic[a[i] * j], j)
      else:
        dic[a[i] * j] = j

for q in qs:
  print(res[q] if res[q] != inf and res[q] <= k else -1)
