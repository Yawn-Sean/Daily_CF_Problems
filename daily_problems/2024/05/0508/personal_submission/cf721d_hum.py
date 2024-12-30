from heapq import heapify, heappop, heappush

n, k, x = map(int, input().split())
a = list(map(int, input().split()))

cnt = sum(1 for x in a if x < 0)

hpq = [(abs(v), i) for i, v in enumerate(a)]
heapify(hpq)
c = 0
while hpq and c < k:
  _, i = heappop(hpq)
  if a[i] < 0:
    if cnt % 2 == 0:
      a[i] += x
      if a[i] >= 0:
        cnt -= 1
    else:
      a[i] -= x
  else:
    if cnt % 2 == 0:
      a[i] -= x
      if a[i] < 0:
        cnt += 1
    else:
      a[i] += x

  heappush(hpq, (abs(a[i]), i))
  c += 1

print(*a)
