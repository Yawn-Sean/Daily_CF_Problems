import heapq

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
idx = sorted(range(n), key=lambda x: a[x])

hpq = []

s = 0
now = 0
i = 0
res = 0

while i < n or hpq:
  if len(hpq) == 0:
    now = a[idx[i]]

  while i < n and a[idx[i]] == now:
    heapq.heappush(hpq, -b[idx[i]])
    s += b[idx[i]]
    i += 1

  s -= -heapq.heappop(hpq)
  res += s
  now += 1

print(res)
