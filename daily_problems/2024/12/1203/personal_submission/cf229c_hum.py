import math

n, m = map(int, input().split())
cnt = [0] * n

for _ in range(m):
  u, v = map(lambda x: int(x) - 1, input().split())
  cnt[u] += 1
  cnt[v] += 1

angles = 0
for i in range(n):
  angles += cnt[i] * (n - 1 - cnt[i])

print(math.comb(n, 3) - angles // 2)
