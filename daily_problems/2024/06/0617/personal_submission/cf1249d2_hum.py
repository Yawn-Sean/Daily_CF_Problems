from heapq import heappush, heappop

n, k = map(int, input().split())
m = int(2e5) + 2
pos = [[] for _ in range(m)]
diff = [0] * m
for i in range(n):
  l, r = map(int, input().split())
  diff[l] += 1
  diff[r + 1] -= 1
  pos[l].append((r, i))

hpq = []
res = []
s = 0
for i in range(m):
  s += diff[i]
  for r, idx in pos[i]:
    heappush(hpq, (-r, idx))
  while s > k:
    r, idx = heappop(hpq)
    s -= 1
    diff[-r + 1] += 1
    res.append(idx + 1)

print(len(res))
print(*res)
