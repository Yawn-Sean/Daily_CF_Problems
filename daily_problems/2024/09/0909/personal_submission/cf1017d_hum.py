import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()

n, m, q = map(int, input().split())
w = list(map(int, input().split()))
w.reverse()

lim = 1 << n
cnt = [0] * lim

for _ in range(m):
  s = input()
  cnt[int(s, 2)] += 1

val = [0] * lim
for i in range(lim):
  for j in range(n):
    if i >> j & 1:
      val[i] += w[j]

d = [[0] * 101 for _ in range(lim)]
for i in range(lim):
  for k in range(lim):
    if cnt[k]:
      t = val[(lim - 1) ^ i ^ k]
      if t <= 100:
        d[i][t] += cnt[k]

for i in range(lim):
  d[i] = list(accumulate(d[i]))

for _ in range(q):
  t, k = input().split()
  t = int(t, 2)
  k = int(k)
  print(d[t][k])
