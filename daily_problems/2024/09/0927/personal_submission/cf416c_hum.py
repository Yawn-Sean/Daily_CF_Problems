import heapq
import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = []
for i in range(n):
  c, p = map(int, input().split())
  a.append((c, p, i))

k = int(input())
b = list(map(int, input().split()))
a.sort()
j = 0
hpq = []
res = []
ans = 0
for i in sorted(range(k), key=lambda x: b[x]):
  cur = b[i]
  while j < n and a[j][0] <= cur:
    heapq.heappush(hpq, (-a[j][1], a[j][2]))
    j += 1
  if hpq:
    v, idx = heapq.heappop(hpq)
    ans += -v
    res.append((i + 1, idx + 1))

print(len(res), ans)
for i, j in res:
  print(j, i)
