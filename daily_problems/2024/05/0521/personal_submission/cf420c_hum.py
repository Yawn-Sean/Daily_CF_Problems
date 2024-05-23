import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
n, p = map(int, input().split())
cnt = [0] * n
c = Counter()
for _ in range(n):
  a, b = map(lambda x: int(x) - 1, input().split())
  cnt[a] += 1
  cnt[b] += 1
  if a > b:
    a, b = b, a
  c[(a, b)] += 1

cnt.sort()

res = 0

l = 0
for r in range(n - 1, -1, -1):
  while l < r and cnt[r] + cnt[l] < p:
    l += 1
  if l < r:
    res += r - l

for (a, b), v in c.items():
  if cnt[a] + cnt[b] >= p > cnt[a] + cnt[b] - v:
    res -= 1

print(res)
