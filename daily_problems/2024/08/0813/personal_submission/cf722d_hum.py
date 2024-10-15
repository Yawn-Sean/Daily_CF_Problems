from heapq import heapify, heapreplace

n = int(input())
a = list(map(int, input().split()))

hpq = [-c for c in a]
heapify(hpq)
vis = set(a)

while True:
  old = -hpq[0]
  u = old
  while u in vis:
    u //= 2
  if u == 0:
    break
  heapreplace(hpq, -u)

  vis.remove(old)
  vis.add(u)

print(*[-c for c in hpq])
