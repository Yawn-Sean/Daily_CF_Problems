from math import inf

n, m = map(int, input().split())
mi = [inf] * n
cnt = [0] * n
for _ in range(m):
  a, b = map(lambda x: int(x) - 1, input().split())
  mi[a] = min(mi[a], (b - a) % n)
  cnt[a] += 1

res = []
for i in range(n):
  tmp = 0
  for j in range(n):
    if cnt[j]:
      tmp = max(tmp, (cnt[j] - 1) * n + mi[j] + (j - i) % n)
  res.append(tmp)
print(*res)
