from collections import Counter
from heapq import heappop, heappush, heapify

n, m = map(int, input().split())
a = list(map(int, input().split()))
hpq = [(0, x) for x in range(1, 10 ** 6 + 1) if x != m]
heapify(hpq)
cnt = Counter()
s = set(list(range(1, 10 ** 6 + 1)))
s.remove(m)

for x in a:
  cnt[x] += 1

  if x == m:
    while hpq and hpq[0][0] < cnt[x]:
      _, y = heappop(hpq)
      if cnt[y] < cnt[x]:
        s.remove(y)
  else:
    if x in s:
      heappush(hpq, (cnt[x], x))

  if not hpq:
    print(-1)
    exit()

print(hpq[0][1])
