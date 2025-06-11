class FenwickTree:
  def __init__(self, n):
    self.N = n
    self.bit = [0] * n

  def get_sum(self, l, r):
    if l > r:
      return 0
    return self.__get_sum(r) - self.__get_sum(l - 1)

  def __get_sum(self, r):
    res = 0
    while r >= 0:
      res += self.bit[r]
      r = (r & (r + 1)) - 1
    return res

  def add(self, idx, v):
    while idx < self.N:
      self.bit[idx] += v
      idx = idx | (idx + 1)


import sys
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
qs = defaultdict(list)

res = [-1] * n
for i in range(n):
  a, t, x = map(int, input().split())
  qs[x].append((a, t, i))

for q in qs.values():
  ts = sorted(set([t for _, t, _ in q]))
  d = {t: i for i, t in enumerate(ts)}
  m = len(ts)
  fen = FenwickTree(m)

  for a, t, i in q:
    if a == 1:
      fen.add(d[t], 1)
    elif a == 2:
      fen.add(d[t], -1)
    else:
      res[i] = fen.get_sum(0, d[t])

for x in res:
  if x != -1:
    print(x)
