from heapq import heapify, heappop, heappush

n, k = map(int, input().split())
hpq = []
a = []
for i in range(64):
  if (n >> i) & 1:
    hpq.append(-i)
    a.append(-i)

heapify(hpq)

if k < len(hpq):
  print("No")
  exit()

print("Yes")

while len(hpq) < k:
  u = -heappop(hpq)
  heappush(hpq, -u + 1)
  heappush(hpq, -u + 1)

m = -heappop(hpq)

heapify(a)
while -a[0] > m:
  u = -heappop(a)
  heappush(a, -u + 1)
  heappush(a, -u + 1)

res = [-c for c in a]
res.sort(reverse=True)

while len(res) < k:
  u = res.pop()
  res.append(u - 1)
  res.append(u - 1)

print(*res)
