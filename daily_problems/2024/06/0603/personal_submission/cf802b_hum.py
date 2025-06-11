from heapq import heappush, heappop

n, k = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))

hpq = []
last = [n] * n
right = [0] * n
for i in range(n - 1, -1, -1):
  right[i] = last[a[i]]
  last[a[i]] = i

vis = [0] * n
res = 0
cnt = 0
for i in range(n):
  if not vis[a[i]]:
    res += 1
    cnt += 1

  while cnt > k:
    _, x = heappop(hpq)
    if not vis[x]:
      continue
    cnt -= 1
    vis[x] = 0

  heappush(hpq, (-right[i], a[i]))
  vis[a[i]] = 1

print(res)
