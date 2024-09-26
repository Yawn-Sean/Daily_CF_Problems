from collections import Counter

n, a, b = map(int, input().split())

cnt1 = Counter()
cnt2 = Counter()

res = 0

for _ in range(n):
  x, vx, vy = map(int, input().split())

  res += cnt1[vy - a * vx] - cnt2[(vx, vy)]

  cnt1[vy - a * vx] += 1
  cnt2[(vx, vy)] += 1

print(res * 2)
