from heapq import *
inf = float("inf")
n = int(input())
t, w = map(int, input().split())
a = []
for i in range(n - 1):
  x, y = map(int, input().split())
  a.append((x, y))
a.sort(key=lambda x: -x[0])
hpq = []
ans = inf
j = 0
while True:
  while j < n - 1 and a[j][0] > t:
    heappush(hpq, a[j][1] - a[j][0] + 1)
    j += 1
  ans = min(ans, len(hpq) + 1)
  if hpq and hpq[0] <= t:
    t -= heappop(hpq)
  else:
    break
print(ans)
