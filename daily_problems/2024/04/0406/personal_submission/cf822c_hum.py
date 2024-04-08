import sys
from collections import defaultdict
from math import inf

input = lambda: sys.stdin.readline().rstrip()

n, x = map(int, input().split())
base = 2 * 10 ** 5
tmp_in = [[] for _ in range(base + 1)]
tmp_out = [[] for _ in range(base + 1)]
for _ in range(n):
  a, b, c = map(int, input().split())
  tmp_in[a].append((b - a + 1, c))
  tmp_out[b].append((b - a + 1, c))

d = defaultdict(lambda: inf)
res = inf

for i in range(base + 1):
  for l, c in tmp_in[i]:
    res = min(res, c + d[x - l])

  for l, c in tmp_out[i]:
    d[l] = min(d[l], c)

print(res if res != inf else -1)
